#ifndef _P2_CLASS_H_
#define _P2_CLASS_H_

class Date{
    private:
        int year, month, day;
    public:
        Date();
        bool setYear(int y);
        bool setMonth(int m);
        bool setDay(int d);
        int getYear();
        int getMonth();
        int getDay();
};

class Employee{
    protected:
        char *name, *ID;
        Date hireDate;
    public:
        Employee(const char *,const char *);
        Employee();
        ~Employee();
        const char *getName();
        const char *getID();
        bool setName(char *name);
        bool setID(char *ID);
};

class EmployeePay: public Employee{
    protected:
        float monthSalary;
        int department;
    public:
        EmployeePay(char *name, char *ID, float mSalary, int depart):
        Employee(name, ID){
            monthSalary = mSalary;
            department = depart;
        }
        EmployeePay(){
            monthSalary = 0;
            department = 0;
        }
        void  setSalary(float s);
        void  setDepart(int d);
        float getSalary();
        int getDepart();
};

#endif
