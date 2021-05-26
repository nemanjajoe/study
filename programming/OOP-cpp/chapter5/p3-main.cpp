//************************************************************************
//* program auther: NemanjaJoe
//* date: May 26th, 2021
//* chapter: 5
//* quiz index: 3
//* description: design a class called HourlyPay, which is the subclass of quzi
//*              2(last quzi). data menber of this class can store information
//*              below:
//*                 1.salary per hour of general work time;
//*                     validation: neither less than 0 nor greater than 50
//*                 2.salary per hour of extra work time;
//*                     validation: neither less than 0 nor greater than 100,
//*                                 and should greater than general work time
//*                                 salary rate;
//*                 3.worked time;
//*                     validation: neither less than 0 nor greater than 176
//*              note: program should check data validation.
//************************************************************************

#include "p3-class.h"
#include <iostream>

#define LEN 64

using namespace std;

void displayInfo(HourlyPay &m){
    cout<<"name      : "<<m.getName()<<endl;
    cout<<"ID        : "<<m.getID()<<endl;
    cout<<"department: "<<m.getDepart()<<endl;
    cout<<"general salary/hour: "<<m.getGen()<<endl;
    cout<<"extra salary/hour  : "<<m.getExtra()<<endl;
    cout<<"worked time        : "<<m.getTime()<<endl;
}

int main(){
    HourlyPay man;
    char name[LEN], ID[LEN], ch;
    float genSalary, extraSalary, workedTime;
    int department;
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

        cout<<"input worked time:"<<endl;
        cin>>workedTime;
        while(!man.setTime(workedTime)){
            cout<<"worked time are neither less than 0 nor greater than 176 hours"<<endl;
            cout<<"input again!"<<endl;
            cin>>workedTime;
        }

        displayInfo(man);
        cout<<"quit program ? [y/n]:"<<endl;
        cin>>ch;
        if(ch == 'y') break;
    }while(1);
return 0;
}
