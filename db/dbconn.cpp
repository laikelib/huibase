
#include <sstream>
#include "dbconn.h"

namespace HUIBASE {

namespace MYSQL {

CMysqlConnection::CMysqlConnection() {}
    
CMysqlConnection::CMysqlConnection(HCSTRR db, HCSTRR host, HCSTRR user, HCSTRR pw,
				   HINT port, HBOOL opened )
    :m_db(db), m_host(host), m_port(port),
     m_user(user), m_pw(pw), m_opened(opened){

}

CMysqlConnection::~CMysqlConnection() {

    using namespace mysqlpp;
    
    if (connected()) {
	disconnect();
    }
    
    
}

HRET CMysqlConnection::Connect(){

    using namespace mysqlpp;
    
    auto cb = connect(m_db.c_str(), m_host.c_str(),
			       m_user.c_str(), m_pw.c_str(), m_port);

    if (not cb) {
	HRETURN(DB_DISCONN);
    }


    HRETURN_OK;
}


HRET CMysqlConnection::ReConnect() {

    using namespace mysqlpp;

    if (connected()) {
	disconnect();
    }

    
    return Connect();

}


void CMysqlConnection::SetConnInfo(const CONN_INFO &ci) {

    m_db = ci.m_db;
    m_host = ci.m_host;
    m_port = ci.m_port;
    m_user = ci.m_user;
    m_pw = ci.m_pw;
    
}


HSTR CMysqlConnection::Profile() {

    stringstream ss;
    ss << "host[" << m_host << "]"
       << " port[" << m_port << "]";

    return ss.str();
    
}


HRET CMysqlConnection::SetUtf8() {

    using namespace mysqlpp;

    auto cb = set_option(new SetCharsetNameOption("utf8"));

    if (not cb) {

	HRETURN(DB_DISCONN);

    }

    HRETURN_OK;
    
}

}

}
