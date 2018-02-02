

#ifndef __HCRYPTO_H__
#define __HCRYPTO_H__

#include "huibase.h"

namespace HUIBASE {

namespace CRYPTO {

    HRET Base64Encode (HCSTRR strIn, HSTRR strOut);

    HRET Base64Decode (HCSTRR strIn, HSTRR strOut);

}	

}

#endif //__HCRYPTO_H__


