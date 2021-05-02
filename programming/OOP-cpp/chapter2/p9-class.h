#ifndef _P9_CLASS_H_
#define _P9_CLASS_H_

#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct student_t {
    char name[21];
    int age;
    char phone[14];
    char E_mail[51];
    char address[51];
};

class Contact{
    public:
        // constructor and deconstructor
        Contact(){
            this->count = 0;
            cout<<"contact constructed"<<endl;
        };
        ~Contact(){
            cout<<"contact deconstructed"<<endl;
        };
        // object interface
        void add(student_t &student);
        void displayAll();
        void modify(int recNum);
        void find(char* name);
        void deletePerson(int recNum);
    private:
        Contact(Contact &);
        void operator = (Contact &);
        fstream file;

        char fileName[128];
        int count;
        void test();
};
#endif
