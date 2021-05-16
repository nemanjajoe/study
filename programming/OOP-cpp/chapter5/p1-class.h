#ifndef _P1_CLASS_H_
#define _P1_CLASS_H_
class Time{
    protected:
        int hour, min, sec;
    public:
        Time(int h = 0, int m = 0, int s = 0){
            hour = h;
            min = m;
            sec = s;
        };
        int getHour(){return hour;}
        int getMin(){return min;}
        int getSec(){return sec;}
        void setHour(int h){hour = h;}
        void setMin(int m){min = m;}
        void setSec(int s){sec = s;}
};

class MilTime : public Time{
    protected:
        int milHour, milSeconds;
    public:
        MilTime(int miliTime = 0, int sec = 0){
            hour = 0;
            setTime(miliTime, sec);
        }
        bool setTime(int miliTime, int sec);
        int getHour();
        int getStandHr(){
            int h = hour;
            if(hour > 12) h -= 12;
            return h;
        }
};
#endif
