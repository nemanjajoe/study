#ifndef _CLASS_H_
#define _CLASS_H_
#include<iostream>
#include<string.h>

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
        Dog(char *str){

        };
        void eat();
        void bark();
    private:
        char name[];
        int legs;
        void sort();
};
#endif
