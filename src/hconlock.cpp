

#include "hconlock.h"

namespace HUIBASE {

HRET CConLock::Wait() {

    return HCCond::Wait(*this);

}

}
