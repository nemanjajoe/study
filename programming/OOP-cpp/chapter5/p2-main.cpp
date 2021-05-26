//************************************************************************
//* program auther: NemanjaJoe
//* date: May 17th, 2021
//* chapter: 5
//* quiz index: 2
//* description: design a class called Employee, its data members can store the
//*              information below:
//*                 employee name: presented by char * pointer.
//*                 employee ID: formated by XXX-L, X is a number bewteen
//*                 0 ~ 9, L is a letter bewteen A ~ M.
//*                 hire date: presented by designing a class.
//*              add constructor, deconstructor and other relevent function members
//*              to this class. constructor can dynamically allocate memory for
//*              storing names, deconstructor can delete the allocated memory.
//*              then design a sub-class of Employee called EmployeePay, it has
//*              data members below:
//*                 monthly salary: presented by a float variable.
//*                 department number: presented by a int variable.
//*              complete this program, which allows user to input employee
//*              information with keyboard, then displays it on screen to check
//*              if program works correctly.
//************************************************************************

#include "p2-class.h"
#include <iostream>

#define LEN 64

using namespace std;

void displayInfo(EmployeePay &m){
    cout<<"name: "<<m.getName()<<endl;
    cout<<"ID  : "<<m.getID()<<endl;
    cout<<"salary/month: "<<m.getSalary()<<endl;
    cout<<"department: "<<m.getDepart()<<endl;
}

int main(){
    EmployeePay man;
    char name[LEN], ID[LEN], ch;
    float salary;
    int department;
    do{
        cout<<"input your name:"<<endl;
        cin>>name;
        if(!man.setName(name)){
            cout<<"incorrect name format, input again!"<<endl;
            cin>>name;
        }
        cout<<"input your ID:"<<endl;
        cin>>ID;
        if(!man.setID(ID)){
            cout<<"incorrect ID format, input again!"<<endl;
            cin>>ID;
        }
        cout<<"input monthly salary:"<<endl;
        cin>>salary;
        man.setSalary(salary);
        cout<<"input your department:"<<endl;
        cin>>department;
        man.setDepart(department);
        displayInfo(man);
        cout<<"quit program ? [y/n]:"<<endl;
        cin>>ch;
        if(ch == 'y') break;
    }while(1);
    return 0;
}
