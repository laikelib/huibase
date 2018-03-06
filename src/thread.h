

#ifndef __THREAD_H__
#define __THREAD_H__

#include "huibase.h"
#include "hthread.h"
#include "hthreadid_t.h"
#include <pthread.h>
#include "htime.h"

namespace HUIBASE {

    class CThread {
    public:
        using handle_type = pthread_t;

        using pid_t = cid<handle_type>;

        typedef void* (*thread_fun_t)(void*);

    public:
        CThread () {}

        CThread (const HCThreadAttr& attr, thread_fun_t fun, void* arg);

        HRET Create (const HCThreadAttr& attr, thread_fun_t fun, void* arg);

        HRET Create (thread_fun_t fun, void* arg);

        HRET Cancel ();

        HRET Join (void** retval);

        HRET Detach ();



    private:
        pid_t m_id{};

    };


}


#endif //__THREAD_H__
