
#include "hexception.h"
#include "hfilelock.h"
#include "hlog.h"

namespace HUIBASE {

HCFileLock::HCFileLock(HCSTRR strPathFileName) {

	m_fd = open(strPathFileName.c_str(), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

	HASSERT_THROW(m_fd > 0, SYS_FAILED);

}


HCFileLock::~HCFileLock () {

	HCLOSE_FD(m_fd);

}


HRET HCFileLock::Fcntl (HINT iCmd, HINT iType, HINT offset, HINT iLen, HINT iWhere) {

	struct flock stLock;
	stLock.l_type = iType;
	stLock.l_start = offset;
	stLock.l_whence = iWhere;
	stLock.l_len = iLen;

	while (fcntl(m_fd, iCmd, &stLock) < 0) {

		HASSERT_THROW(errno == EINTR, SYS_FAILED);

		continue;
		
	}

	HRETURN_OK;
}

CAppLockException::CAppLockException(HINT err, HBOOL bComm, HBOOL bError,
	HINT iLineNo, HCPSZ szFile) :
	HCException(err, bComm, bError, iLineNo, szFile){	
}


HRET CAppLock::LockApp(HCPSZ szFileName) throw(CAppLockException) {

    HASSERT_RETURN((m_fd = open(szFileName, O_CREAT | O_RDWR, 0644)) >= 0, SYS_FAILED);
	
    HASSERT_RETURN(lockf(m_fd, F_TEST, 0) >= 0, LOGIC_ERR);

    HASSERT_RETURN(lockf(m_fd, F_LOCK, 0) >= 0, SYS_FAILED);

    HRETURN_OK;

}



CAppLock::~CAppLock() {


	if (m_fd > 0) {

	    LOG_NS("release file lock");
		HASSERT_THROW_MSG(lockf(m_fd, F_ULOCK, 0) >= 0,"unlock file lock failed.",SYS_FAILED);

		close(m_fd);
	
	}	


}


}

