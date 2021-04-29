#ifndef _P0_CLASS_H_
#include<iostream>
#define _P0_CLASS_H_
#define MAX 10
#define BOUNDARY 9

using namespace std;

class Set {
    public:
        Set(){
            init();
        };
        void getMax();
        void getMin();
        void init();
    private:
        int number[MAX];
};
#endif
