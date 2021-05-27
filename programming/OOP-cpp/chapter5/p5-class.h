#ifndef _P5_CLASS_H_
#define _P5_CLASS_H_

#include "p3-class.h"
#include "p4-class.h"

class DailyPay:public HourlyPay,public TimeClock{
    private:
        float daySalary;
        void  calSalary();
    public:
        DailyPay();
        ~DailyPay();
        float getDaySalary();
};
#endif
