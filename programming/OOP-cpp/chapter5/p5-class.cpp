#include "p5-class.h"

DailyPay::DailyPay(){
    daySalary = 0;
}
DailyPay::~DailyPay(){}

void DailyPay::calSalary(){
    float genRate = getGen(),
          extraRate = getExtra(),
          time = getDiffHours();
    if(time > 8){
        daySalary += 8 * genRate;
        daySalary += (time - 8) * extraRate;
    }else{
        daySalary += time * genRate;
    }
}

float DailyPay::getDaySalary(){
    calSalary();
    return daySalary;
}
