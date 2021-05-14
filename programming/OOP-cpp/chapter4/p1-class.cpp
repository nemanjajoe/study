#include "p1-class.h"
#include<iostream>

using namespace std;

NumDays::NumDays(float hours){
    this->hours = hours;
    this->calculateDays();
}

NumDays::NumDays(const NumDays &obj){
    this->days = obj.days;
    this->hours = obj.hours;
}

NumDays::~NumDays(){

}

bool NumDays::setHours(float hours){
    if(hours < 0){
        return false;
    }
    this->hours = hours;
    this->calculateDays();
    return true;
}

bool NumDays::setDays(float days){
    if(days < 0){
        return false;
    }
    this->days = days;
    this->calculateHours();
    return true;
}

float NumDays::getHours(){
    return this->hours;
}

float NumDays::getDays(){
    return this->days;
}

NumDays NumDays::operator+(const NumDays &obj){
    NumDays temp;
    temp.setHours(this->hours + obj.hours);
    return temp;
}

NumDays NumDays::operator-(const NumDays &obj){
    NumDays temp;
    temp.setHours(this->hours - obj.hours);
    return temp;
}

void NumDays::operator++(){
     this->hours = this->hours + 1;
     this->calculateDays();
}

void NumDays::operator++(int){
     this->hours = this->hours + 1;
     this->calculateDays();
}

void NumDays::operator--(){
    this->hours = this->hours - 1;
    this->calculateHours();
}

void NumDays::operator--(int){
    this->hours = this->hours - 1;
    this->calculateHours();
}
