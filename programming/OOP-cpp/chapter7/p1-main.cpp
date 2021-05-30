//************************************************************************
//* program auther: NemanjaJoe
//* date: May 30th, 2021
//* chapter: 7
//* quiz index: 1
//* description: min and max functions are frequently used. min accepts tow
//*              parameters, then return the minima. max also accepts tow
//*              parameters, then return the maxima. write a completed program,
//*              define templates for them, make sure this tow templates can
//*              handle all the kinds of primitives.
//************************************************************************

#include "p1-class.hpp"
#include <iostream>

using namespace std;

int main(){
    cout<<"compare int type: "<<endl;
    int int1, int2;
    cin>>int1>>int2;
    cout<<"minima: "<<min(int1, int2)<<endl;
    cout<<"maxima: "<<max(int1, int2)<<endl;

    cout<<"compare char type: "<<endl;
    char ch1, ch2;
    cin>>ch1>>ch2;
    cout<<"minima: "<<min(ch1, ch2)<<endl;
    cout<<"maxima: "<<max(ch1, ch2)<<endl;

    cout<<"compare float type: "<<endl;
    float f1, f2;
    cin>>f1>>f2;
    cout<<"minima: "<<min(f1, f2)<<endl;
    cout<<"maxima: "<<max(f1, f2)<<endl;
return 0;
}
