//************************************************************************
//* program auther: NemanjaJoe
//* date: May 30th, 2021
//* chapter: 7
//* quiz index: 2
//* description: write a function template, which return the absolute value.
//************************************************************************

#include <iostream>

using namespace std;

template <typename T>
T abs(T &v){
    return v > 0 ? v : -v;
}

int main(){
    int i;
    float f;
    cout<<"input a value(int type): "<<endl;
    cin>>i;
    cout<<"absolute value is "<<abs(i)<<endl;

    cout<<"input a value(float type): "<<endl;
    cin>>f;
    cout<<"absolute value is "<<abs(f)<<endl;

    return 0;
}
