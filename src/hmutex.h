

#ifndef __HMUTEX_H__
#define __HMUTEX_H__

#include "huibase.h"
#include "hthreadid_t.h"
#include <pthread.h>
#include "hcond.h"

namespace HUIBASE {

class HCMutexAttr{
public:
	using attr_type = pthread_mutex_t;
	using attr_type_ptr = pthread_mutex_t*; 

	HCMutexAttr () throw (HCException);

	HCMutexAttr (const HCMutexAttr& attr) = delete;		

	~ HCMutexAttr();

	const pthread_mutexattr_t* GetAttrP ()const { return &m_attr; }

private:
	pthread_mutexattr_t m_attr;
};

class HCMutex {
public:
	friend class HCCond;
	using handle_type = pthread_mutex_t;

	using mid_t = cid<handle_type>;

	HCMutex () throw (HCException);

	HCMutex (const HCMutexAttr& attr) throw (HCException);

	HCMutex (const HCMutex& ) = delete;

	HCMutex (HCMutex&& other)   noexcept: m_id(other.m_id)  {
		other.m_id = mid_t{};
	}

	virtual ~ HCMutex();

	HRET Lock () throw (HCException);

	HRET UnLock () throw (HCException);

private:
	mid_t m_id;

};


}

#endif //__HMUTEX_H__



