#include "SimpleThroughputLogic.h"
#include <limits.h>

using namespace dash::mpd;
using namespace libdash::framework::adaptation;
using namespace libdash::framework::input;
using namespace libdash::framework::mpd;

SimpleThroughputLogic::SimpleThroughputLogic(IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet) :
                  AbstractAdaptationLogic(mpd, period, adaptationSet) { }

SimpleThroughputLogic::~SimpleThroughputLogic() {
}

LogicType SimpleThroughputLogic::GetType() {
    return adaptation::SimpleThroughput;
}

IRepresentation* SimpleThroughputLogic::GetRepresentation  () {
    float avg_throughput = this->metrics->GetThroughput() * 1024 * 8; // KBps transform to bps
    const std::vector<IRepresentation *>& reps = this->adaptationSet->GetRepresentation();
    int best_idx = -1, best_bw = -1, least_idx = -1, least_bw = INT_MAX, cur_bw;
    
    for (int i = 0; i < reps.size(); ++i) {
        cur_bw = reps[i]->GetBandwidth();
        if (cur_bw <= least_bw) {
            least_bw = cur_bw;
            least_idx = i;
        }
        if (avg_throughput >= cur_bw && best_bw <= cur_bw) {
            best_bw = cur_bw;
            best_idx = i;
        }
    }
    // std::cout << "[BUPT DEBUG][qt/SimpleThroughputLogic.cpp] " << this->metrics->GetThroughput() << " avg_tpt=" << avg_throughput << " choose bw=" << reps.at(best_idx != -1 ? best_idx : least_idx)->GetBandwidth() << std::endl; 
    return reps.at(best_idx != -1 ? best_idx : least_idx);
}

