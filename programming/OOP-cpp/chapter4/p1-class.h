#ifndef _P1_CLASS_H_
#define _P1_CLASS_H_

using namespace std;

class NumDays{
    public:
        bool setHours(float hours);
        bool setDays(float days);
        float getHours();
        float getDays();
        NumDays(float);
        NumDays(const NumDays &obj);
        ~NumDays();

        float operator+(const NumDays &obj);
        float operator-(const NumDays &obj);
        void  operator++();
        void  operator++(int);
        void  operator--();
        void  operator--(int);
    private:
        float days;
        float hours;
        void calculateHours(){
            hours = days * 8;
        };
        void calculateDays(){
            days = hours / 8;
        };
};
#endif
