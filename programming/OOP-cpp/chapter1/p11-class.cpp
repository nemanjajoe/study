#include "p11-class.h"
#include<iomanip>
using namespace std;

// helper functions of print();
void printDate(date_t date){
    const char *months[12] = {
       " Januay   "," February "," March    "," April   ",
       " May      "," June     "," July     "," August  ",
       " September"," October  "," November "," December"
    };
    cout<<"date: "<<months[date.month - 1]<<" "<<date.day<<"th , "<<date.year<<endl;
}
void printName(char* name){
    cout<<"name: "<<name<<endl;
}
void printMoney(float money){
    cout<<"money: "<<fixed<<setprecision(2)<<money<<endl;
}

// print the formating information of this cheque
void Cheque::print(){
    printDate(date);
    printName(name);
    printMoney(cash);
}

// helper functions of init()
void getDate(date_t  &date){
    char blank[] = "     ";
    int year, month, day;
    cout<<"input date: "<<endl;
    cout<<blank<<"which year ?"<<endl;
    while((cin>>year) < 0){
        cout<<"no such year, input again!"<<endl;
    }
    cout<<blank<<"which month ?"<<endl;
    while((cin>>month) < 0 || month > 12){
        cout<<"error month type, input again!"<<endl;
    }
    cout<<blank<<"which day ?"<<endl;
    while((cin>>day) < 0 || day > 31){
        cout<<"error day type, input again!"<<endl;
    }
    date.year = year;
    date.month = month;
    date.day = day;
}
void getName(char* name){
    char temp[QUAN];
    cout<<"input person's name: "<<endl;
    cin>>temp;
    strcpy(name, temp);
}
void getCash(float &cash){
    cout<<"input amount of money(maximun of acception is 1000 RMB): "<<endl;
    while((cin>>cash) < 0 || cash > 1000){
        cout<<"amount of money is limited (money should not less than 0 and more than 1000 RMB)"<<endl;
        cout<<"please input again!"<<endl;
    }
}
// initailize an object
void Cheque::init(){
    getDate(date);
    getName(name);
    getCash(cash);
}

// unit testing function
void Cheque::test(){
    // given test dada
    date_t testDate;
    testDate.year = 2021;
    testDate.month = 4;
    testDate.day = 31;
    char testName[] = "Musk";
    float testCash = 898.21;
    // the expect output
    cout<<endl<<"expect output start: >>>>>>>>>>>>>>>>>>>>>>"<<endl;
    printDate(testDate);
    printName(testName);
    printMoney(testCash);
    cout<<"expect output end  : >>>>>>>>>>>>>>>>>>>>>>"<<endl;
    //set test data to insatance
    date = testDate;
    strcpy(name, testName);
    cash = testCash;
    // testing functionality
    cout<<endl<<"actual test output start: >>>>>>>>>>>>>>>>>"<<endl;
    this->print();
    cout<<"actual test output end  : >>>>>>>>>>>>>>>>>"<<endl;
}
