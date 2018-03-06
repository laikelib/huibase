

#ifndef __HCON_LOCK_H__
#define __HCON_LOCK_H__

#include "hcond.h"
#include "hmutex.h"

namespace HUIBASE {

class CConLock : public HCMutex, public HCCond {
public:
    CConLock () {}

    HRET Wait ();

};

}


#endif //__HCON_LOCK_H__
