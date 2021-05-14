#include "p2-class.h"
#include "p1-class.h"
#include <string.h>
#include <iostream>

using namespace std;

bool TimeOff::setMaxSick(float days){
    return maxSickDays.setDays(days)? true : false;
}

bool TimeOff::setMaxVacation(float days){
    return maxVacDays.setDays(days)? true : false;
}

bool TimeOff::setMaxUnpaid(float days){
    return maxUnpaid.setDays(days)? true : false;
}

bool TimeOff::addSickDay(float days){
    if(this->sickTaken.getDays() + days >= maxSickDays.getDays()){
        return false;
    }
    return sickTaken.setDays(days + sickTaken.getDays())? true : false;
}

bool TimeOff::addVacDay(float days){
    if(this->vacTaken.getDays() + days >= maxVacDays.getDays()){
        return false;
    }
    return vacTaken.setDays(days + vacTaken.getDays())? true : false;
}

bool TimeOff::addUnpaidDay(float days){
    if(this->unpaidTaken.getDays() + days >= maxUnpaid.getDays()){
        return false;
    }
    return unpaidTaken.setDays(days + unpaidTaken.getDays())? true : false;
}

NumDays TimeOff::getSickTaken(){
    NumDays temp = this->sickTaken;
    return temp;
}

NumDays TimeOff::getVacTaken(){
    NumDays temp = this->vacTaken;
    return temp;
}

NumDays TimeOff::getUnpaidTaken(){
    NumDays temp = this->unpaidTaken;
    return temp;
}

char* TimeOff::getName(){
    if(this->name == NULL){
        cout<<"name has not defined yet"<<endl;
    }
    return this->name;
}
char* TimeOff::getID(){
    if(this->ID == NULL){
        cout<<"undefined ID";
    }
    return this->ID;
}
bool TimeOff::setName(const char *name){
    this->name = new char[strlen(name)];
    if(this->name == NULL){
        return false;
    }
    strcpy(this->name, name);
    return true;
}
bool TimeOff::setID(const char *ID){
    this->ID = new char[strlen(ID)];
    if(this->ID == NULL){
        return false;
    }
    strcpy(this->ID,ID);
    return true;
}

TimeOff::TimeOff(){
    setMaxSick(15);
    setMaxVacation(1);
    setMaxUnpaid(15);
    name = NULL;
    ID = NULL;
}

TimeOff::TimeOff(const char *name,const char *ID){
    setName(name);
    setID(ID);
}

TimeOff::~TimeOff(){
}
