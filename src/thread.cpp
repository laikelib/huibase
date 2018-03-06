

#include "thread.h"


namespace HUIBASE {


    CThread::CThread(const HCThreadAttr& attr, thread_fun_t fun, void* arg) {

        auto cb = pthread_create(m_id.GetIdP(), attr.GetAttrP(), fun, arg);

        HASSERT_THROW_MSG(cb == 0, "pthread_create failed", SYS_FAILED);

    }



    HRET CThread::Create(const HCThreadAttr &attr, thread_fun_t fun, void *arg) {

        auto cb = pthread_create(m_id.GetIdP(), attr.GetAttrP(), fun, arg);

        HASSERT_RETURN(cb == 0, SYS_FAILED);

        HRETURN_OK;

    }


    HRET CThread::Create(thread_fun_t fun, void *arg) {

        auto cb = pthread_create(m_id.GetIdP(), nullptr, fun, arg);

        HASSERT_RETURN(cb == 0, SYS_FAILED);

        HRETURN_OK;

    }



    HRET CThread::Cancel() {

        auto cb = pthread_cancel(m_id.GetId());

        HASSERT_RETURN(cb == 0, SYS_FAILED);

        HRETURN_OK;

    }


    HRET CThread::Join(void** retval) {

        auto cb = pthread_join(m_id.GetId(), retval);

        HASSERT_RETURN(cb == 0, SYS_FAILED);

        HRETURN_OK;

    }


    HRET CThread::Detach() {

        auto cb = pthread_detach(m_id.GetId());

        HASSERT_RETURN(cb == 0, SYS_FAILED);

        HRETURN_OK;

    }


}
