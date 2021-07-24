/*
 * MultimediaManager.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MultimediaManager.h"

using namespace libdash::framework::input;
using namespace libdash::framework::adaptation;
using namespace libdash::framework::buffer;
using namespace sampleplayer::managers;
using namespace sampleplayer::renderer;
using namespace dash::mpd;

// unit: second
#define VIDEO_SEGMENTBUFFER_SIZE 10
#define AUDIO_SEGMENTBUFFER_SIZE 20000

MultimediaManager::MultimediaManager            (QTGLRenderer *videoElement, QTAudioRenderer *audioElement) :
                   videoElement                 (videoElement),
                   audioElement                 (audioElement),
                   mpd                          (NULL),
                   period                       (NULL),
                   videoAdaptationSet           (NULL),
                   videoRepresentation          (NULL),
                   videoLogic                   (NULL),
                   videoStream                  (NULL),
                   audioAdaptationSet           (NULL),
                   audioRepresentation          (NULL),
                   audioLogic                   (NULL),
                   audioStream                  (NULL),
                   isStarted                    (false),
                   framesDisplayed              (0),
                   segmentsDownloaded           (0),
                   isVideoRendering             (false),
                   isAudioRendering             (false)
{
    InitializeCriticalSection (&this->monitorMutex);

    this->manager = CreateDashManager();
    av_register_all();
}
MultimediaManager::~MultimediaManager           ()
{
    this->Stop();
    this->manager->Delete();

    DeleteCriticalSection (&this->monitorMutex);
}

IMPD*   MultimediaManager::GetMPD                           ()
{
    return this->mpd;
}
bool    MultimediaManager::Init                             (const std::string& url)
{
    EnterCriticalSection(&this->monitorMutex);
    this->mpd = this->manager->Open((char *)url.c_str());
    if(this->mpd == NULL)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return false;
    }

    LeaveCriticalSection(&this->monitorMutex);
    return true;
}
void    MultimediaManager::Start                            ()
{
    /* Global Start button for start must be added to interface*/
    if (this->isStarted)
        this->Stop();

    EnterCriticalSection(&this->monitorMutex);
    if (this->videoAdaptationSet && this->videoRepresentation)
    {
        this->InitVideoRendering(0);
        this->videoStream->Start();
        this->StartVideoMonitorThread();
        this->StartVideoRenderingThread();
    }

    if (this->audioAdaptationSet && this->audioRepresentation)
    {
        this->InitAudioPlayback(0);
        this->audioElement->StartPlayback();
        this->audioStream->Start();
        this->StartAudioMonitorThread();
        this->StartAudioRenderingThread();
    }

    this->isStarted = true;

    LeaveCriticalSection(&this->monitorMutex);
}
void    MultimediaManager::Stop                             ()
{
    if (!this->isStarted)
        return;

    EnterCriticalSection(&this->monitorMutex);

    this->StopVideo();
    this->StopAudio();

    this->isStarted = false;

    LeaveCriticalSection(&this->monitorMutex);
}
void    MultimediaManager::StopVideo                        ()
{
    if(this->isStarted && this->videoStream)
    {
        this->videoStream->Stop();
        this->StopVideoRenderingThread();
        this->StopMonitorThread("video");

        delete this->videoStream;
        delete this->videoLogic;

        this->videoStream = NULL;
        this->videoLogic = NULL;
    }
}
void    MultimediaManager::StopAudio                        ()
{
    if (this->isStarted && this->audioStream)
    {
        this->audioStream->Stop();
        this->StopAudioRenderingThread();
        this->StopMonitorThread("audio");

        this->audioElement->StopPlayback();

        delete this->audioStream;
        delete this->audioLogic;

        this->audioStream = NULL;
        this->audioLogic = NULL;
    }
}
bool    MultimediaManager::SetVideoQuality                  (IPeriod* period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    EnterCriticalSection(&this->monitorMutex);
    this->period                = period;
    this->videoAdaptationSet    = adaptationSet;
    this->videoRepresentation   = representation;

    if (this->videoStream)
        this->videoStream->SetRepresentation(this->period, this->videoAdaptationSet, this->videoRepresentation);

    LeaveCriticalSection(&this->monitorMutex);
    return true;
}
bool    MultimediaManager::SetAudioQuality                  (IPeriod* period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    EnterCriticalSection(&this->monitorMutex);

    this->period                = period;
    this->audioAdaptationSet    = adaptationSet;
    this->audioRepresentation   = representation;

    if (this->audioStream)
        this->audioStream->SetRepresentation(this->period, this->audioAdaptationSet, this->audioRepresentation);

    LeaveCriticalSection(&this->monitorMutex);
    return true;
}
bool    MultimediaManager::SetVideoAdaptationLogic          (libdash::framework::adaptation::LogicType type)
{
    //Currently unused, always using ManualAdaptation.
    return true;
}
bool    MultimediaManager::SetAudioAdaptationLogic          (libdash::framework::adaptation::LogicType type)
{
    //Currently unused, always using ManualAdaptation.
    return true;
}
void    MultimediaManager::AttachManagerObserver            (IMultimediaManagerObserver *observer)
{
    this->managerObservers.push_back(observer);
}
void    MultimediaManager::NotifyVideoBufferObservers       (uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnVideoBufferStateChanged(fillstateInPercent);
}
void    MultimediaManager::NotifyVideoSegmentBufferObservers(uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnVideoSegmentBufferStateChanged(fillstateInPercent);
}
void    MultimediaManager::NotifyAudioSegmentBufferObservers(uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnAudioSegmentBufferStateChanged(fillstateInPercent);
}
void    MultimediaManager::NotifyAudioBufferObservers       (uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnAudioBufferStateChanged(fillstateInPercent);
}
void    MultimediaManager::InitVideoRendering               (uint32_t offset)
{
    this->videoLogic = AdaptationLogicFactory::Create(libdash::framework::adaptation::SimpleThroughput, this->mpd, this->period, this->videoAdaptationSet);

    this->videoStream = new MultimediaStream(sampleplayer::managers::VIDEO, this->mpd, VIDEO_SEGMENTBUFFER_SIZE, 20, 0);
    this->videoStream->AttachStreamObserver(this);
    this->videoStream->SetRepresentation(this->period, this->videoAdaptationSet, this->videoRepresentation);
    this->videoStream->SetPosition(offset);
}
void    MultimediaManager::InitAudioPlayback                (uint32_t offset)
{
    this->audioLogic = AdaptationLogicFactory::Create(libdash::framework::adaptation::SimpleThroughput, this->mpd, this->period, this->audioAdaptationSet);

    this->audioStream = new MultimediaStream(sampleplayer::managers::AUDIO, this->mpd, AUDIO_SEGMENTBUFFER_SIZE, 0, 20);
    this->audioStream->AttachStreamObserver(this);
    this->audioStream->SetRepresentation(this->period, this->audioAdaptationSet, this->audioRepresentation);
    this->audioStream->SetPosition(offset);
}
void    MultimediaManager::OnSegmentDownloaded              ()
{
    this->segmentsDownloaded++;
}
void    MultimediaManager::OnSegmentBufferStateChanged    (StreamType type, uint32_t fillstateInPercent)
{
    switch (type)
    {
        case AUDIO:
            this->NotifyAudioSegmentBufferObservers(fillstateInPercent);
            break;
        case VIDEO:
            this->NotifyVideoSegmentBufferObservers(fillstateInPercent);
            break;
        default:
            break;
    }
}
void    MultimediaManager::OnVideoBufferStateChanged      (uint32_t fillstateInPercent)
{
    this->NotifyVideoBufferObservers(fillstateInPercent);
}
void    MultimediaManager::OnAudioBufferStateChanged      (uint32_t fillstateInPercent)
{
    this->NotifyAudioBufferObservers(fillstateInPercent);
}
void    MultimediaManager::SetFrameRate                     (double framerate)
{
    this->frameRate = framerate;
}

bool    MultimediaManager::StartVideoRenderingThread        ()
{
    this->isVideoRendering = true;

    this->videoRendererHandle = CreateThreadPortable (RenderVideo, this);

    if(this->videoRendererHandle == NULL)
        return false;

    return true;
}
void    MultimediaManager::StopVideoRenderingThread         ()
{
    this->isVideoRendering = false;

    if (this->videoRendererHandle != NULL)
    {
        JoinThread(this->videoRendererHandle);
        DestroyThreadPortable(this->videoRendererHandle);
    }
}
bool    MultimediaManager::StartAudioRenderingThread        ()
{
    this->isAudioRendering = true;

    this->audioRendererHandle = CreateThreadPortable (RenderAudio, this);

    if(this->audioRendererHandle == NULL)
        return false;

    return true;
}
void    MultimediaManager::StopAudioRenderingThread         ()
{
    this->isAudioRendering = false;

    if (this->audioRendererHandle != NULL)
    {
        JoinThread(this->audioRendererHandle);
        DestroyThreadPortable(this->audioRendererHandle);
    }
}
void*   MultimediaManager::RenderVideo        (void *data)
{
    MultimediaManager *manager = (MultimediaManager*) data;

    QImage *frame = manager->videoStream->GetFrame();

    while(manager->isVideoRendering)
    {
        if (frame)
        {
            manager->videoElement->SetImage(frame);
            manager->videoElement->update();

            manager->framesDisplayed++;
            PortableSleep(1 / manager->frameRate);

            delete(frame);
        }
        frame = manager->videoStream->GetFrame();
    }

    return NULL;
}
void*   MultimediaManager::RenderAudio        (void *data)
{
    MultimediaManager *manager = (MultimediaManager*) data;

    AudioChunk *samples = manager->audioStream->GetSamples();

    while(manager->isAudioRendering)
    {
        if (samples)
        {
            manager->audioElement->WriteToBuffer(samples->Data(), samples->Length());
            PortableSleep(1 / manager->frameRate);

            delete samples;
        }

        samples = manager->audioStream->GetSamples();
    }

    return NULL;
}

bool MultimediaManager::StartVideoMonitorThread() {
    this->videoMonitorHandle = CreateThreadPortable(MonitorVideo, this);
    return this->videoMonitorHandle != NULL;
}

bool MultimediaManager::StartAudioMonitorThread() {
    this->audioMonitorHandle = CreateThreadPortable(MonitorAudio, this);
    return this->audioMonitorHandle != NULL;
}

void MultimediaManager::StopMonitorThread(const std::string& type) {
    if (type == "video") {
        this->isVideoMonitoring = false;
        if (this->videoMonitorHandle != NULL) {
            JoinThread(this->videoMonitorHandle);
            DestroyThreadPortable(this->videoMonitorHandle);
        }
    } else if (type == "audio") {
        this->isAudioMonitoring = false;
        if (this->videoMonitorHandle != NULL) {
            JoinThread(this->videoMonitorHandle);
            DestroyThreadPortable(this->videoMonitorHandle);
        }
    }
}

void* MultimediaManager::MonitorVideo (void *data) {
    MultimediaManager *manager = (MultimediaManager*) data;
    Monitor(manager, "video");
    return NULL;
}

void* MultimediaManager::MonitorAudio (void *data) {
    MultimediaManager *manager = (MultimediaManager*) data;
    Monitor(manager, "audio");
    return NULL;
}

void MultimediaManager::Monitor(MultimediaManager* manager, const std::string& type) {
    bool* EoM = NULL;
    MultimediaStream* stream = NULL;
    const DASHMetrics* metrics = NULL;
    IRepresentation** rep = NULL;
    IAdaptationLogic* logic = NULL;
    int last_rep_bw = -1;

    if (type == "video") {
        EoM = &manager->isVideoMonitoring;
        stream = manager->videoStream;
        rep = &manager->videoRepresentation;
        logic = manager->videoLogic;
    } else if (type == "audio") {
        EoM = &manager->isAudioMonitoring;
        stream = manager->audioStream;
        rep = &manager->audioRepresentation;
        logic = manager->audioLogic;
    } else {
        std::cout << "[ERROR][qt/MultimediaManager.cpp] unknown monitor type: " << type << std::endl;
    }

    metrics = stream->GetMetrics();
    logic->SetMetrics(metrics);
    while (*EoM) {
        stream->UpdateMetrics();
        std::cout << "[DEBUG][qt/MultimediaManager.cpp] StreamType=" << type \
                  << " Buffer Level=" << metrics->GetBufferLevel() << "s "\
                  << " AvgThroughput=" << metrics->GetThroughput() * 8 << "Kbps " \
                  << " CurrentRepID=" << (*rep)->GetId() \
                  << " CurrentRepBandwidth=" << (*rep)->GetBandwidth() << "bps" << std::endl;
        
        IRepresentation* target_rep = logic->GetRepresentation();
        if (target_rep->GetBandwidth() != (*rep)->GetBandwidth()) {
            std::cout << "[DEBUG][qt/MultimediaManager.cpp] ABR Change from " \ 
                      << (*rep)->GetBandwidth() << " to " << target_rep->GetBandwidth() << std::endl;
            
            if (type == "video") {
                manager->SetVideoQuality(manager->period, manager->videoAdaptationSet, target_rep);
            } else if (type == "audio") {
                manager->SetAudioQuality(manager->period, manager->audioAdaptationSet, target_rep);
            }
        }
        PortableSleep(1);        
    }
}

