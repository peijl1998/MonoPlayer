#include "DASHMetrics.h"

using namespace libdash::framework::input;



DASHMetrics::DASHMetrics(int maxHistoryLen) : 
    maxHistoryLen(maxHistoryLen),
    bufferLevel(-1) {

}

DASHMetrics::~DASHMetrics() {}

float DASHMetrics::GetBufferLevel() const {
    return this->bufferLevel;
}

void DASHMetrics::SetBufferLevel(float bufferLevel) {
    this->bufferLevel = bufferLevel;
}

float DASHMetrics::GetThroughput(ThroughputType type) const {
    if (type == AVG) {
        return this->GetAverageThroughput();
    } else {
        std::cout << "[BUPT WARN][qt/DASHMetrics]  TPT type not supported, use AVG\n";
        return this->GetAverageThroughput();    
    }
}

void DASHMetrics::AddThroughput(float bytes, float duration) {
    if (this->throughputHistory.size() >= this->maxHistoryLen) {
        this->throughputHistory.pop_front();
    }
    this->throughputHistory.push_back(std::make_pair(bytes, duration));
}

float DASHMetrics::GetAverageThroughput() const {
    float tpt_sum = 0;
    int count = 0;
    for (auto item : this->throughputHistory) {
        tpt_sum += (item.first / (item.second == 0 ? 1 : item.second));
        count += 1;
    }
    
    return tpt_sum / count;
}
