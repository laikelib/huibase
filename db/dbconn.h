
#ifndef __DBCONN_H__
#define __DBCONN_H__


#include <huibase.h>
#include <hstr.h>
#include <mysql++.h>

namespace HUIBASE {

namespace MYSQL {

typedef struct {
    HSTR m_host;
    HINT m_port;
    HSTR m_user;
    HSTR m_pw;
    HSTR m_db;
}CONN_INFO;

class CMysqlConnection : public mysqlpp::Connection {
public:
    CMysqlConnection(); 
    
    CMysqlConnection(HCSTRR db, HCSTRR host, HCSTRR user, HCSTRR pw,
		     HINT port, HBOOL opened = HFALSE);

    ~CMysqlConnection ();

    HRET Connect ();

    HRET ReConnect ();

    void SetConnInfo (const CONN_INFO& ci);

    HSTR Profile ();

    HRET SetUtf8 ();

private:
    HSTR m_db;
    HSTR m_host;
    HINT m_port;
    HSTR m_user;
    HSTR m_pw;
    HBOOL m_opened;

};

}

}

#endif //__DBCONN_H__









