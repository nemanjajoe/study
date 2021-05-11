//************************************************************************
//* program auther: NemanjaJoe
//* date: May 11th, 2021
//* chapter: 3
//* quiz index: 4
//* description: design a wage calculation class called Payroll which includes
//*              the data menbers: salary per hour, work time, salary should
//*              be payid this week; defining an array of ten objects in main
//*              function(represents ten employees). this program asks the work
//*              of every employee this week and then displays the
//*              corresponding salary of each employee;
//************************************************************************

#include "p4-class.h"

using namespace std;

#define AMOUNT 10
int main(){
    Payroll employees[AMOUNT];
    float worktime = 0;
    for(int i = 0; i < AMOUNT; i++){ // get work time of every employee
        cout<<"input employee "<<i + 1<<"'s work time this week:"<<endl;
        cin>>worktime;
        while(!employees[i].setWorkTime(worktime)){
            cout<<"work time should be less than 60 hours and greater than 0"<<endl;
            cout<<"input employee "<<i + 1<<"'s work time this week:"<<endl;
            cin>>worktime;
        }
    }
    for(int i = 0; i < AMOUNT; i++){// display each corresponding salary
        cout<<"the "<< i + 1 << " employee's salary this week: ";
        cout<<employees[i].getSalary()<<" RMB"<<endl;;
    }
return 0;
}
