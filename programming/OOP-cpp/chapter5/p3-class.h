#ifndef _P3_CLASS_H_
#define _P3_CLASS_H_

#include "p2-class.h"

class HourlyPay: public EmployeePay{
    private:
        float genSalary, extraSalary, workedTime;
    public:
        HourlyPay();
        ~HourlyPay();
        bool setGen(float rate);
        bool setExtra(float rate);
        bool setTime(float time);
        float getGen();
        float getExtra();
        float getTime();
};

#endif
