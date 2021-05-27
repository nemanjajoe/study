#include "p4-class.h"

TimeClock::TimeClock(){};
TimeClock::~TimeClock(){};

bool TimeClock::setStartTime(int miliTime){
    if(startTime.setTime(miliTime, 0)) return true;
    return false;
}
bool TimeClock::setEndTime(int miliTime){
    if(endTime.setTime(miliTime, 0)) return true;
    return false;
}
float TimeClock::getDiffHours(){
    float start = startTime.getHour()/100 + startTime.getMin()/60.0,
          end   = endTime.getHour()/100 + endTime.getMin()/60.0;
    return end - start;
}
