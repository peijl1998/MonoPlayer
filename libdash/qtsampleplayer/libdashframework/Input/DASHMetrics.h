#ifndef LIBDASH_FRAMEWORK_INPUT_DASHMETRICS_H_
#define LIBDASH_FRAMEWORK_INPUT_DASHMETRICS_H_


#include <deque>
#include <iostream>

namespace libdash {
    namespace framework {
        namespace input {
            enum ThroughputType
            {
                AVG,
                CWND
            };
            class DASHMetrics {
                public:
                    DASHMetrics(int maxHistoryLen);
                    virtual ~DASHMetrics();
                    float GetBufferLevel() const;
                    void SetBufferLevel(float bufferLevel);
                    float GetThroughput(ThroughputType type = AVG) const;
                    void AddThroughput(float bytes, float duration);
                    // std::deque<std::pair<int, int> > GetThroughputHistory();

                private:
                    std::deque<std::pair<int, int> > throughputHistory;
                    int maxHistoryLen;
                    float bufferLevel;

                    float GetAverageThroughput() const;
                    // float GetCwndThroughput();


            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_INPUT_DASHMETRICS_H_ */
