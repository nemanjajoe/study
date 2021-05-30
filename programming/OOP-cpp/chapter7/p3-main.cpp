//************************************************************************
//* program auther: NemanjaJoe
//* date: May 30th, 2021
//* chapter: 7
//* quiz index: 3
//* description: write a function template, which accepts an array and implement summation of
//*              any user input value of any typ and return the sum.
//************************************************************************

#include "p3-templates.h"
#include <iostream>

using namespace std;

int main(){
    float nums[10];
    cout<<"input ten numbers (float type)"<<endl;
    for(int i = 0; i < 10; i++){
        cin>>nums[i];
    }
    cout<<"sum: "<<sum(nums, 10)<<endl;

return 0;
}
