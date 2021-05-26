#include "p3-class.h"

HourlyPay::HourlyPay(){
    genSalary = 0;
    extraSalary = 0;
    workedTime = 0;
}

HourlyPay::~HourlyPay(){}

bool HourlyPay::setGen(float rate){
    if(rate < 0 || rate > 50) return false;
    genSalary = rate;
    return true;
}

bool HourlyPay::setExtra(float rate){
    if(rate < 0 || rate > 100 || rate < genSalary) return false;
    extraSalary = rate;
    return true;
}

bool HourlyPay::setTime(float time){
    if(time < 0 || time > 176) return false;
    workedTime = time;
    return true;
}

float HourlyPay::getGen(){
    return genSalary;
}

float HourlyPay::getExtra(){
    return extraSalary;
}

float HourlyPay::getTime(){
    return workedTime;
}
