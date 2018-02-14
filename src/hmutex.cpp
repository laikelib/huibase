

#include "hmutex.h"

namespace HUIBASE {

HCMutexAttr::HCMutexAttr() throw (HCException){

	auto cb = pthread_mutexattr_init(&m_attr);
	HASSERT_THROW(cb == 0, SYS_FAILED);

}


HCMutexAttr::~HCMutexAttr() {

	(void)pthread_mutexattr_destroy(&m_attr);

}

HCMutex::HCMutex () throw (HCException) {

	auto cb = pthread_mutex_init(m_id.GetIdP(), nullptr);
	HASSERT_THROW(cb == 0, SYS_FAILED);

}

HCMutex::HCMutex (const HCMutexAttr& attr) throw (HCException) {

	auto cb = pthread_mutex_init(m_id.GetIdP(), attr.GetAttrP());
	HASSERT_THROW(cb == 0, SYS_FAILED);
	
}


HCMutex::~HCMutex() {

	(void)pthread_mutex_destroy(m_id.GetIdP());

}


HRET HCMutex::Lock () throw (HCException){

	auto cb = pthread_mutex_lock(m_id.GetIdP());
	HASSERT_THROW(cb == 0, SYS_FAILED);

	HRETURN_OK;

}

HRET HCMutex::UnLock () throw (HCException) {
	auto cb = pthread_mutex_unlock(m_id.GetIdP());
	HASSERT_THROW(cb == 0, SYS_FAILED);

	HRETURN_OK;
}

}


