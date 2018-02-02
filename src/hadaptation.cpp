


#include "hadaptation.h"

namespace HUIBASE {


void husleep(HINT usec) {

	struct timeval _val{};
	_val.tv_sec = 0;
	_val.tv_usec = usec;

	select(0, NULL, NULL, NULL, &_val);

}

void hsleep(HINT sec) {

	struct timeval _val{};
	_val.tv_sec = sec;
	_val.tv_usec = 0;

	select(0, NULL, NULL, NULL, &_val);


}


}

