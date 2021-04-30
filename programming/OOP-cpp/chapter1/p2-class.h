#ifndef _P2_CLASS_H_
#define _P2_CLASS_H_
#include<iostream>

#define MONTH 12

using namespace std;

struct _data_t {
    int month;
    float rainfall;
} data_t;

class RainData{
    public:
        RainData(){
            cout<<"making object in type RainData"<<endl;
            init();
        };
        ~RainData(){
            cout<<"desolving object"<<endl;
        };
        void getAverage();
        void getTotal();
        void getMax();
        void getMin();
    private:
        typedef data_t data[MONTH];
        void init();
};

#endif
