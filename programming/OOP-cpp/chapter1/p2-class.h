#ifndef _P2_CLASS_H_
#define _P2_CLASS_H_
#include<iostream>
#include<iomanip>
#define MONTH 12

using namespace std;

typedef struct _data_t {
    int month;
    float rainfall;
} data_t;

class RainData{
    public:
        RainData(){
            cout<<"making object in type RainData"<<endl;
            for(int i = 0; i < MONTH; i++){
                data_t d;
                data[i] = d;
            }
            test();
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
        data_t data[MONTH];
        void init();
        void test();
        void sort();
};

#endif
