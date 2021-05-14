#ifndef _P2_CLASS_H_
#define _P2_CLASS_H_

#include "p1-class.h"

#define NAME_LENGTH 32
#define ID_LENGTH   16

class TimeOff{
    public:
        bool setMaxSick(float days);
        bool setMaxVacation(float days);
        bool setMaxUnpaid(float days);

        bool addSickDay(float days);
        bool addVacDay(float days);
        bool addUnpaidDay(float days);

        NumDays getSickTaken();
        NumDays getVacTaken();
        NumDays getUnpaidTaken();

        char* getName();
        char* getID();
        bool setName(const char* name);
        bool setID(const char* ID);

        TimeOff();
        TimeOff(const char* name,const char* ID);
        ~TimeOff();
    private:
        NumDays maxSickDays;
        NumDays maxVacDays;
        NumDays maxUnpaid;
        NumDays sickTaken;
        NumDays vacTaken;
        NumDays unpaidTaken;

        char *name;
        char *ID;
};

#endif
