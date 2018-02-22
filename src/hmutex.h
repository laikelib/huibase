/****************************************************************************
 *
 * File Name: hmutex.h
 *
 * Create Author: Tom Hui, tomhui1009@yahoo.com, 8613760232170
 *
 * Create Date: Thu Dec 08 16:16 2016
 *
 * Description:
 *	pthread mutex lock.
 *
 ****************************************************************************/

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

class CConLock : public HCMutex, public HCCond {
public:
	CConLock () {}



};


class CRwlockAttr {
public:
	using attr_type = pthread_rwlock_t;
	using attr_type_ptr = pthread_rwlock_t*;

	CRwlockAttr ();

	CRwlockAttr (const CRwlockAttr& attr ) = delete;

	~ CRwlockAttr ();

private:
	pthread_rwlockattr_t m_attr;


};


 class CRwlock {
 public:
	 using handle_type = pthread_rwlock_t;
	 using id_t = cid<handle_type>;

	 CRwlock ();

	 CRwlock (const CRwlockAttr& attr);

	 CRwlock (const CRwlock& rwlock ) = delete;

	 CRwlock (CRwlock&& rw ) noexcept : m_id(rw.m_id) {

		 rw.mid = id_t {};

	 }

	 virtual ~ CRwlock ();

	 HRET RLock ();

	 HRET WLock ();

	 HRET Unlock ();


 private:
	 id_t m_id;
 };

}

#endif //__HMUTEX_H__



