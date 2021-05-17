//************************************************************************
//* program auther: NemanjaJoe
//* date: May 16th, 2021
//* chapter: 5
//* quiz index: 1
//* description: with the given class Time. design a sub-class of Time called
//*              MilTime, which can convert the 24 hours time format (military
//*              time format) into the standard time format (12 hours format).
//*              this class has data and function members below:
//* data members: milHours: store the format of 24 hours. for example: store
//*                         1:00PM into 1300, 4:30PM into 1630.
//*               milSeconds: store the standard time format.
//* func menbers: constructor: it has tow parameters, one for the military time
//*                            format, another for seconds.according to parameters
//*                            constructor converts them into the standard time
//*                            and store them in hours, min and sec data members of
//*                            Time class correspondingly.
//*               setTime: function store the accepted parameters into milHour and
//*                        milSeconds variables, then convert them into standard time
//*                        storing to hours, min, sec each.
//*               getHour: return the time of military time format.
//*               getStandHr: return the time of standard time format.
//* note: program can display time of military format and standard format after user
//*       input the time of military format. MilTime neither accepts time that greater
//*       2359 or less than 0, nor takes in the seconds greater than 59 or less than 0.
//************************************************************************

#include "p1-class.h"
#include <iostream>

using namespace std;

int main(){
    MilTime mt1(1735,45);
    cout<<"military hour: "<<mt1.getHour()<<endl;
    cout<<"standard hour: "<<mt1.getStandHr()<<endl;
    cout<<"main function"<<endl;;
return 0;
}



