#ifndef _P4_CLASS_H_
#define _P4_CLASS_H_

#include<iostream>

using namespace std;

class Payroll{
    public:
        Payroll(float wageRate = 16.0){
            this->wageRate = wageRate;
            cout<<"object constructed"<<endl;
            cout<<wageRate<<" RMB per hour"<<endl;
        };
        ~Payroll(){
        };
        bool setWorkTime(float time);
        bool setWageRate(float rate);
        float getSalary();
    private:
        int workTime;
        float wageRate;
        float salary;
        void calculateSalary();
};
#endif
