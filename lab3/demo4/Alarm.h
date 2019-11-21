#ifndef ALARM_H
#define ALARM_H

#include "list.h"

class Alarm{
public:
	Alarm(); 
	~Alarm(); 
	void Pause(int howLong);
	void awake();	
	static int num;// record the num of list;
private:
	List  *list;
	
};

	

#endif

