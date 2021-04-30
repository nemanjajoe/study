#ifndef _P11_CLASS_H_
#define _P11_CLASS_H_

#include<string.h>
#include<iostream>
//#include<iomanip>
#define QUAN 64

using namespace std;

struct date_t {
    int year;
    int month;
    int day;
};

class Cheque{
    public:
        Cheque(){ // constructor function
            cout<<"constructing  an object"<<endl;
            test();
            init();
        };
        ~Cheque(){ // resolving function
            cout<<"resolving an object"<<endl;
        };

        void print();
    private:
        date_t date;
        char name[QUAN];
        float cash;
        void init();
        void test();
};

#endif
