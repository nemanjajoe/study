#include "p0-class.h"

using namespace std;

// initailize and sort this numbers
void Set::init(){
    //get numbers from user
    for(int i = 0; i < MAX; i++){
        cout<<"input a number:";
        cin>>this->number[i];
        cout<<"number "<<i + 1<<": is "<<number[i]<<endl;
    }
    //sort the array with bubule sorting
    for(int i = BOUNDARY, temp = 0; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(number[j] > number[j + 1]){
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
}

// get the maximun
void Set::getMax(){
    int current = number[BOUNDARY];
    cout<<endl<<"maximun number: "<<current;
    for (int i = BOUNDARY - 1; (i > 0) && (current == number[i]); i--){
            current = number[i];
            cout<<"     "<<current;
    }
    cout<<endl;
}

void Set::getMin(){
    int current = number[0];
    cout<<endl<<"minimun number: "<<current;
    for (int i = 1; (i < MAX) && (current == number[i]); i++){
        current = number[i];
        cout<<"     "<<current;
    }
    cout<<endl;
}
