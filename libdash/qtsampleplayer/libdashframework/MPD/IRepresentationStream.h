/*
 * IRepresentationStream.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_MPD_IREPRESENTATIONSTREAM_H_
#define LIBDASH_FRAMEWORK_MPD_IREPRESENTATIONSTREAM_H_

#include "ISegment.h"

namespace libdash
{
    namespace framework
    {
        namespace mpd
        {
            enum RepresentationStreamType
            {
                SingleMediaSegment,
                SegmentList,
                SegmentTemplate,
                UNDEFINED
            };
            
            enum StreamContentType
            {
                UNKNOWN,
                VIDEO,
                AUDIO,
                WEBM_VIDEO,
                WEBM_AUDIO
            };
            
            typedef struct Cue{
                Cue(int ct, int cp) : cue_time(ct),
                                      cue_pos(cp) { }
                int cue_time;
                int cue_pos;
            } Cue;
            
            class IRepresentationStream
            {
                public:
                    virtual ~IRepresentationStream () {}
                   
                    // It's for segmentBase and it will be overriden by SingleSegmentStream.
                    virtual dash::mpd::ISegment* GetIndexRangeSegment() = 0;
                    virtual void SetSegList(const std::vector<Cue>& cues, uint64_t segmentStart, uint64_t segmentEnd,
                                            uint64_t segmentDuration, uint64_t timescale) = 0;

                    virtual dash::mpd::ISegment*        GetInitializationSegment        () = 0;
                    virtual dash::mpd::ISegment*        GetIndexSegment                 (size_t segmentNumber) = 0;
                    virtual dash::mpd::ISegment*        GetMediaSegment                 (size_t segmentNumber) = 0;
                    virtual dash::mpd::ISegment*        GetBitstreamSwitchingSegment    () = 0;
                    virtual RepresentationStreamType    GetStreamType                   () = 0;
                    virtual uint32_t                    GetSize                         () = 0;
                    virtual uint32_t                    GetFirstSegmentNumber           () = 0;
                    virtual uint32_t                    GetCurrentSegmentNumber         () = 0;
                    virtual uint32_t                    GetLastSegmentNumber            () = 0;
                    virtual uint32_t                    GetAverageSegmentDuration       () = 0;
                    virtual StreamContentType           GetStreamContentType            () = 0;
                    virtual void                        SetStreamContentType            (StreamContentType type) = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_MPD_IREPRESENTATIONSTREAM_H_ */
