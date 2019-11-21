#include "list.h"

#ifndef ALARM_H
#define ALARM_H

class Alarm {
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
