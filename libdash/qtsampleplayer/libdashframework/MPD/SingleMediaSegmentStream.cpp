/*
 * SingleMediaSegmentStream.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SingleMediaSegmentStream.h"

using namespace dash::mpd;
using namespace libdash::framework::mpd;

SingleMediaSegmentStream::SingleMediaSegmentStream      (IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation) :
                          AbstractRepresentationStream  (mpd, period, adaptationSet, representation)
{
    this->baseUrls = BaseUrlResolver::ResolveBaseUrl(mpd, period, adaptationSet, 0, 0, 0);
    this->segList.push_back(this->representation->GetBaseURLs().at(0)->ToMediaSegment(baseUrls));
}
SingleMediaSegmentStream::~SingleMediaSegmentStream     ()
{
    for (auto x : this->segList) {
        if (x) {
            delete x;
            x = NULL;
        }
    }
}

void SingleMediaSegmentStream::SetSegList(const std::vector<Cue>& cues,
                                          uint64_t segmentStart,
                                          uint64_t segmentEnd,
                                          uint64_t segmentDuration,
                                          uint64_t timescale) {
    // clear seglist
    for(auto it = this->segList.begin(); it != this->segList.end();) {
        delete *it;
        it = this->segList.erase(it);
    }
     
    timescale = 1000000000 / timescale;
    // generate seglist
    for (int i = 0; i < cues.size(); ++i) {
        ISegment* seg = this->representation->GetBaseURLs().at(0)->ToMediaSegment(baseUrls);
        
        int start = cues[i].cue_pos + segmentStart;
        int end;
        if (i != cues.size() - 1) {
            seg->SetSegDuration( (float)(cues[i + 1].cue_time - cues[i].cue_time) / timescale );
            // std::cout <<  (float)(cues[i + 1].cue_time - cues[i].cue_time) / timescale << " " << timescale << std::endl;
            end = cues[i + 1].cue_pos + segmentStart - 1;
        } else {
            seg->SetSegDuration( (float)(segmentDuration - cues[i].cue_time) / timescale );
            end = segmentEnd - 1;
        }
        std::cout << cues[i].cue_pos << std::endl;
        seg->Range(std::to_string(start) + "-" + std::to_string(end));
        
        this->segList.push_back(seg);
    }
}

ISegment* SingleMediaSegmentStream::GetIndexRangeSegment() {
    ISegment* seg = this->representation->GetBaseURLs().at(0)->ToMediaSegment(baseUrls);
    seg->Range(this->representation->GetSegmentBase()->GetIndexRange());
    return seg;
}

ISegment*                   SingleMediaSegmentStream::GetInitializationSegment      ()
{
    if (this->representation->GetSegmentBase())
    {
        /* TODO: check whether @sourceURL and/or @range is available in SegmentBase.Initialization, see Table 13 */
        IURLType* init = this->representation->GetSegmentBase()->GetInitialization();
        if (init->GetSourceURL() == "") {
           init->SetSourceURL(this->representation->GetBaseURLs().at(0)->GetUrl()); 
        }
        return init->ToSegment(baseUrls);
    }

    return NULL;
}

ISegment*                   SingleMediaSegmentStream::GetIndexSegment               (size_t segmentNumber)
{
    /* segmentNumber is not used in this case */
    if (this->representation->GetSegmentBase())
    {
        if (this->representation->GetSegmentBase()->GetRepresentationIndex())
            return this->representation->GetSegmentBase()->GetRepresentationIndex()->ToSegment(baseUrls);
    }

    return NULL;
}

ISegment*                   SingleMediaSegmentStream::GetMediaSegment               (size_t segmentNumber)
{
    return segmentNumber >= this->segList.size() ? NULL : this->segList[segmentNumber];
    /*
    if (segmentNumber > 0) {
        return NULL;
    }
    if (this->representation->GetBaseURLs().size() > segmentNumber)
        return this->representation->GetBaseURLs().at(segmentNumber)->ToMediaSegment(baseUrls);
    
    return this->representation->GetBaseURLs().at(0)->ToMediaSegment(baseUrls);
    */
}
ISegment*                   SingleMediaSegmentStream::GetBitstreamSwitchingSegment  ()
{
    /* not possible */
    return NULL;
}
RepresentationStreamType    SingleMediaSegmentStream::GetStreamType                 ()
{
    return SingleMediaSegment;
}
uint32_t                    SingleMediaSegmentStream::GetFirstSegmentNumber           ()
{
    return 0;
}
uint32_t                    SingleMediaSegmentStream::GetCurrentSegmentNumber         ()
{
    return 0;
}
uint32_t                    SingleMediaSegmentStream::GetLastSegmentNumber            ()
{
    return 0;
}
