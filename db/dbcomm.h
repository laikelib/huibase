

#ifndef __DBCOMM_H__
#define __DBCOMM_H__

#include <huibase.h>
#include <hdict.h>
#include <mysql++.h>
#include "dbconn.h"

namespace HUIBASE {

namespace MYSQL {
    
using DBRes = std::vector<HCParam>;

class CMysqlCommand {
public:
    typedef enum {BaseComm, QueryComm, UpdateComm, InsertComm, DeleteComm} CommType;
public:
    CMysqlCommand(CMysqlConnection* conn);

    virtual HINT Query (HCSTRR sql, DBRes& res);

    virtual HINT Update(HCSTRR sql);

    virtual HINT Insert(HCSTRR sql);

    virtual HINT Delete (HCSTRR sql);

    virtual CommType GetCommType () const { return BaseComm; }

protected:
    HINT commExec (HCSTRR sql);
    
    void FetchResult (const mysqlpp::StoreQueryResult& result, DBRes& res);

private:
    CMysqlConnection* m_conn{nullptr};
};


}

}
 
#endif __DBCOMM_H__



