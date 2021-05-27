//************************************************************************
//* program auther: NemanjaJoe
//* date: May 27th, 2021
//* chapter: 5
//* quiz index: 5
//* description: write a program with classes in quzi 3 and 4.
//*              input employee's information, start work time
//*              , end work time , then calculates the salary of this day.
//************************************************************************

#include "p5-class.h"
#include <iostream>

#define LEN 64

using namespace std;

void displayInfo(DailyPay &m){
    cout<<"name      : "<<m.getName()<<endl;
    cout<<"ID        : "<<m.getID()<<endl;
    cout<<"department: "<<m.getDepart()<<endl;
    cout<<"general salary/hour: "<<m.getGen()<<endl;
    cout<<"extra salary/hour  : "<<m.getExtra()<<endl;
    cout<<"worked time today  : "<<m.getDiffHours()<<endl;
    cout<<"total salary today : "<<m.getDaySalary()<<endl;
}

int main(){
    DailyPay man;
    char name[LEN], ID[LEN], ch;
    float genSalary, extraSalary;
    int department, miliTime;
    do{
        cout<<"input your name:"<<endl;
        cin>>name;
        while(!man.setName(name)){
            cout<<"incorrect name format, input again!"<<endl;
            cin>>name;
        }

        cout<<"input your ID:"<<endl;
        cin>>ID;
        while(!man.setID(ID)){
            cout<<"incorrect ID format, input again!"<<endl;
            cin>>ID;
        }

        cout<<"input your department:"<<endl;
        cin>>department;
        man.setDepart(department);

        cout<<"input general salary per hour:"<<endl;
        cin>>genSalary;
        while(!man.setGen(genSalary)){
            cout<<"salary per hour of general work are neither less than 0 nor greater than 50"<<endl;
            cout<<"input again!"<<endl;
            cin>>genSalary;
        }

        cout<<"input salary rate of extra work:"<<endl;
        cin>>extraSalary;
        while(!man.setExtra(extraSalary)){
            cout<<"salary per hour of extra work are neither less than 0 and general salaray rate nor greater than 100;"<<endl;
            cout<<"input again!"<<endl;
            cin>>extraSalary;
        }

        cout<<"input today's start work time in military format:"<<endl;
        cout<<"hours(4:00PM is 1600): ";
        cin>>miliTime;
        while(!man.setStartTime(miliTime)){
            cout<<"input again!"<<endl;
            cout<<"hours(4:00PM is 1600): ";
            cin>>miliTime;
        }

        cout<<"input today's end work time in military format:"<<endl;
        cout<<"hours(4:00PM is 1600): ";
        cin>>miliTime;
        while(!man.setEndTime(miliTime)){
            cout<<"input again!"<<endl;
            cout<<"hours(4:00PM is 1600): ";
            cin>>miliTime;
        }

        displayInfo(man);
        cout<<"quit program ? [y/n]:"<<endl;
        cin>>ch;
        if(ch == 'y') break;
    }while(1);
return 0;
}
