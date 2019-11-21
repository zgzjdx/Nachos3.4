/*

Implementing an Alarm Clock Primitive.

*/
#ifndef ALARM_H
#define ALARM_H

#include "list.h"

class Alarm
{
public:
	Alarm();

	~Alarm();

	// Threads call this function to go to sleep for a period of time. 
	void Pause(int howLong);

	// called when interval has expired
	void AlarmRing();

	// return count of thread waiting for an alarm
	int GetWaiters() { return waiters; }

	// set isNecessaryToFork
	void SetIsNecessaryToFork(bool value) { isNecessaryToFork = value; }

private:
	List *waitQueue;	// a queue of threads waiting for alarm, they are 
						// stored in ascending order by wake-up time.
	int waiters;		// number of waiters

	bool isNecessaryToFork;	// true is necessary
};

#endif
