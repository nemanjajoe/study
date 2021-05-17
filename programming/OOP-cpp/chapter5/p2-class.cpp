#include "p2-class.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void errorQuit(const char *msg){
    cout<<endl;
    cout<<msg;
    cout<<endl;
    exit(0);
}

bool isIDValid(char *ID){
    if(strlen(ID) != 5) return false;
    for(int i = 0; i <3; i++){
        if(ID[i] < '0' || ID[i] > '9'){
            return false;
        }
    }
    if(ID[3] != '-') return false;
    if(ID[4] < 'A' || ID[4] > 'Z') return false;

    return true;
}

Employee::Employee(const char *name,const char *ID){
    this->name = new char[strlen(name) + 1];
    this->ID = new char[strlen(ID) + 1];
    if(this->name == NULL || this->ID == NULL){
       errorQuit("class Employee: memory allocation failed");
    }
    strcpy(this->name, name);
    strcpy(this->ID, ID);
}

Employee::Employee(){
    this->name = NULL;
    this->ID   = NULL;
}

Employee::~Employee(){
    if(this->name != NULL) delete this->name;
    if(this->ID != NULL) delete this->ID;
}

const char* Employee::getName(){
    return this->name;
}
const char* Employee::getID(){
    return this->ID;
}
bool Employee::setName(char *name){
    if(this->name != NULL){
        delete this->name;
    }
    this->name = new char[strlen(name) + 1];
    if(this->name == NULL){
        errorQuit("class Employee::setName : memory allocation failed!");
    }
    strcpy(this->name, name);
    return true;
}
bool Employee::setID(char *ID){
    if(!isIDValid(ID)){
        cout<<"ID format is not correct!"<<endl;
        cout<<"ID format: XXX-L, X is a number [0 ~ 9], L is a letter [A ~ Z]"<<endl;
        return false;
    }
    if(this->ID == NULL){
        this->ID = new char[5];
        if(this->ID == NULL){
            errorQuit("class Employee::setID : memory allocation failed!");
        }
    }
    strcpy(this->ID, ID);
    return true;
}


void  EmployeePay::setSalary(float s){
    monthSalary = s;
}
void  EmployeePay::setDepart(int d){
    department = d;
}
float EmployeePay::getSalary(){
    return monthSalary;
}
int   EmployeePay::getDepart(){
    return department;
}


Date::Date(){
    year = 0;
    month = 0;
    day = 0;
}

bool Date::setYear(int y){
    if(y < 0){
        cout<<"warning: year can't less than 0"<<endl;
        return false;
    }
    year = y;
    return true;
}
bool Date::setMonth(int m){
    if(m < 0 || m > 12){
        cout<<"waring: month can't less than 0 or greater than 12"<<endl;
        return false;
    }
    month = m;
    return true;
}
bool Date::setDay(int d){
    if(d < 0 || d > 30){
        cout<<"warming: day can't less than 0 or greate than 31"<<endl;
        return false;
    }
    day = d;
    return true;
}
int Date::getYear(){
    return year;
}
int Date::getMonth(){
    return month;
}
int Date::getDay(){
    return day;
}
