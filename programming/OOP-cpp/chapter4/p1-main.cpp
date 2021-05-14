//************************************************************************
//* program auther: NemanjaJoe
//* date: May 11th, 2021
//* chapter: 4
//* quiz index: 1
//* description: define a class called NumDays, whose functionaliy is converting
//*              the work time in the form of hour into the form of days.
//*              for example: 8 hours was converted into 1 day, 12 hours was
//*              converted into 1.5 days; the constructor of this class has a
//*              parameter which represents the hours of work time; in addition,
//*              there are also some member functions for storing and retrieving
//*              hours and days; meanwhile, this class should also reload some
//*              operators;
//* operators:
//*            + : plus operator. when tow NumDays objects were added, the reloaded
//*                + operator function should return the sum of hours of each object;
//*            - : minus operator. when tow NumDays objects were subtratcted, the
//*                reloaded - operator function should return the subtraction of
//*                hours of each object;
//*            ++: pre-increment and post-increment operator. the functionality of
//*                this tow functions is to increase 1 of the object's hour data member;
//*                after increment, the days data member should be re-calculated automatically.
//*            --: pre-decrement and post-decrement operator. the functionality of
//*                this tow functions is to decrese 1 of the obkect's hour data menmber;
//*                after decrement, the days data member should be re-calculated automatically.
//************************************************************************

#include "p1-class.h"
#include <iostream>

using namespace std;

int main(){
    NumDays numday1(13), numday2(14);
    cout<<"numday1 hours: "<<numday1.getHours()<<endl;
    cout<<"numday1 days : "<<numday1.getDays()<<endl;
    cout<<"numday2 hours: "<<numday2.getHours()<<endl;
    cout<<"numday2 days : "<<numday2.getDays()<<endl;

    numday1.setHours(18);
    numday2.setDays(5);
    cout<<"after modifed:"<<endl;
    cout<<"numday1 hours: "<<numday1.getHours()<<endl;
    cout<<"numday1 days : "<<numday1.getDays()<<endl;
    cout<<"numday2 hours: "<<numday2.getHours()<<endl;
    cout<<"numday2 days : "<<numday2.getDays()<<endl;

    NumDays numdaySum = numday1 + numday2;
    cout<<"numday1 + numday2 hours: "<<numdaySum.getHours()<<endl;
return 0;
}
