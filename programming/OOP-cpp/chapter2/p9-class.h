#ifndef _P9_CLASS_H_
#define _P9_CLASS_H_

#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

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
            test();
            cout<<"object constructed"<<endl;
        };
        ~Contact(){
            cout<<"object destructed"<<endl;
        };
        // object interface
        void add(student_t &student);
        void displayAll();
        bool modify(int recNum);
        void find(char* name);
        bool deletePerson(int recNum);
        bool open(char *fName);
        void save();
    private:
        Contact(Contact &);
        void operator = (Contact &);
        fstream file;

        char fileName[128];
        int count;
        void test();
};
#endif
