#include "p4-class.h"

using namespace std;

bool Payroll::setWorkTime(float time){
    if(time > 60 || time < 0){
        return false;
    }
    this->workTime = time;
    return true;
}

bool Payroll::setWageRate(float rate){
    if(rate < 0){
        return false;
    }
    this->wageRate = true;
    return true;
}

float Payroll::getSalary(){
    this->calculateSalary();
    return this->salary;
}

void Payroll::calculateSalary(){
    salary = workTime * wageRate;
}
