#ifndef LIBDASH_FRAMEWORK_ADAPTATION_SIMPLETHROUGHPUTLOGIC_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_SIMPLETHROUGHPUTLOGIC_H_

#include "AbstractAdaptationLogic.h"
#include "../MPD/AdaptationSetStream.h"

namespace libdash {
    namespace framework {
        namespace adaptation {
            class SimpleThroughputLogic : public AbstractAdaptationLogic {
                public:
                    SimpleThroughputLogic (dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet);
                    virtual ~SimpleThroughputLogic ();

                    virtual LogicType GetType ();
                    virtual dash::mpd::IRepresentation* GetRepresentation ();
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_ADAPTATION_SIMPLETHROUGHPUTLOGIC_H_ */
