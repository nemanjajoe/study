#include "p1-class.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void reportError(const char *msg){
    cout<<msg;
    cout<<endl;
}

bool MilTime::setTime(int miliTime, int sec){
    if(miliTime < 0 || miliTime > 2359){
        reportError("military hours can't greater than 2359 or less than 0");
        return false;
    }else if(sec < 0 || sec > 59){
        reportError("seconds can't greater than 59 or less than 0");
        return false;
    }
    setHour(miliTime / 100);
    setMin(miliTime % 100);
    setSec(sec);
    this->milHour = miliTime;
    this->milSeconds = sec;
    return true;
}

int MilTime::getHour(){
    return this->milHour;
}

