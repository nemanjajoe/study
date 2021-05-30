//************************************************************************
//* program auther: NemanjaJoe
//* date: May 30th, 2021
//* chapter: 7
//* quiz index: 4
//* description: modify class template SearchArry in this chapter, enable
//*              it binary search instead order search.
//************************************************************************

#include "p4-class.h"
#include <iostream>

using namespace std;

int main(){
    FreeArray <int> arr1(10), arr2;

    for(int i = 0; i < 10; i++){
        arr1[i] = i*100;
    }

    cout<<"arr1: "<<endl;
    for(int i = 0; i < 10; i++){
        cout<<"  "<<arr1[i];
    }
    cout<<endl;

    arr2 = arr1;
    cout<<"arr2: "<<endl;
    for(int i = 0; i < 10; i++){
        arr2[i] /= 10;
        cout<<"  "<<arr2[i];
    }
    cout<<endl;
    return 0;
}
