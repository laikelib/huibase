


#include "dbcomm.h"


namespace HUIBASE {

namespace MYSQL {

CMysqlCommand::CMysqlCommand(CMysqlConnection* conn)
    : m_conn(conn){

    HASSERT_THROW_MSG(m_conn != nullptr, "mysql connection is null pointer", ILL_PT);

}

HINT CMysqlCommand::Query(HCSTRR sql, DBRes& res) {

    mysqlpp::Query qry = m_conn->query();

    qry << sql;

    mysqlpp::StoreQueryResult sqr = qry.store();

    if (!qry) {

	if(2013 == qry.errnum ()) {

	    m_conn->ReConnect();

	    return -1;
	    
	}

    }

    int ret = sqr.num_rows();

    FetchResult(sqr, res);

    return ret;
    
}


HINT CMysqlCommand::Update(HCSTRR sql){

    return commExec(sql);
    
}


HINT CMysqlCommand::Insert(HCSTRR sql){

    return commExec(sql);
    
}

HINT CMysqlCommand::Delete(HCSTRR sql){

    return commExec(sql);
    
}


HINT CMysqlCommand::commExec(HCSTRR sql) {

    mysqlpp::Query qry = m_conn->query();

    qry << sql;

    qry.execute();

    if (!qry) {

	if(2013 == qry.errnum ()) {

	    m_conn->ReConnect();

	    return -1;
	    
	}

    }

    return qry.affected_rows ();
    
}
    

void CMysqlCommand::FetchResult(const mysqlpp::StoreQueryResult& result, DBRes& res) {

    using namespace mysqlpp;

    StoreQueryResult::const_iterator cit = result.begin();

    size_t col_num = result.num_fields();

    for (; cit != result.end(); ++cit) {

	const mysqlpp::Row& row = *cit;

	HCParam ps;

	for (size_t j = 0; j < col_num; ++j) {

	    ps.setValue(result.fields().at(j).name(), HSTR(row.at(j).c_str()));

	}

	res.push_back(ps);

    }

}

    

}

    

}
    








