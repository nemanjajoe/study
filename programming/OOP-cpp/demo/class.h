class Time{
    protected:
        int hour;
    public:
        Time(int h = 0){
            hour = h;
        };
        void setHour(int h){hour = h;}
};
class MilTime : public Time{
    protected:
        int milHour;
    public:
        MilTime(int miliTime = 0){
            setTime(miliTime);
        }
        void setTime(int miliTime){
            setHour(miliTime / 100);
            this->milHour = miliTime;
        };
        int getHour(){return hour;};
};
