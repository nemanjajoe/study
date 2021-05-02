#ifndef _CLASS_H_
#define _CLASS_H_
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

struct point_t {
    int x;
    int y;
};

typedef struct _data_t {
    int year;
    int month;
    int day;
} date_t;

class Dog{
    public:
        Dog(char* name){
            stream.open(name);
        };
        void eat();
        void bark();
    private:
        Dog(Dog &);
        void operator = (Dog &);
        fstream stream;
        int legs;
};
#endif
