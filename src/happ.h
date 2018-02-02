/**************************************************
*	Create Author: TomHui
*	Create Date:
*	Description: this file declare some http tools 
* 				 for making HTTP request and parsing 
*				 HTTP response.
**************************************************/




#ifndef _H_APP_H_
#define _H_APP_H_

#include "huibase.h"
#include "hconf.h"
#include "hfilelock.h"

namespace HUIBASE{

#define EXE_PATH "exe_path"
#define EXE_NAME "exe_name"

void stop_handle(int sig);

class HCHapp{
public:
	HCHapp();
	HCHapp(HINT argc, HCHAR * argv[] );	
	virtual ~ HCHapp();

public:
	virtual HBOOL Run() = 0;
	virtual void Init();		
	
	void Stop () { _running = false; } 

	HBOOL IsRunning () const { HRET_BOOL(_running); }

	void SetConfValue (HCSTRR strKey, HCSTRR strVal) { m_conf.SetValue(strKey, strVal); }

protected:
	
	virtual void init() {}

private:
	void anaOpt(int argc, char ** argv );
	

protected:
	HCSTR GetConfValue( HCSTRR strKey ){
		return m_conf.GetValue( strKey );
	}

	virtual void setDeamonApp();

	virtual HRET lockApp ();

protected:
	HCMapConf m_conf;
	HBOOL m_bDeamon;

private:
	volatile bool _running = true;
	CAppLock m_lock;
};

}

#endif 

