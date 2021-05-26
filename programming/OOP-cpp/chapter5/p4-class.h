#ifndef _P4_CLASS_H_
#define _P4_CLASS_H_

#include "p1-class.h"

class TimeClock: public MilTime{
    private:
        MilTime startTime;
        MilTime endTime;
    public:
        TimeClock();
        ~TimeClock();
        bool setStartTime(int miliTime, int sec);
        bool setEndTime(int miliTime, int sec);
        float getDiffHours();
}

#endif
