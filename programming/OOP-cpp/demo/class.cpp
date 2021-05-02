#include "class.h"

using namespace std;

void demo(){
}

void Dog::eat(){
    cout<<"eating ing ing"<<endl;
}

void Dog::bark(){
    cout<<"won won won"<<endl;
    char ch;
    while(!stream.eof()){
        stream.get(ch);
        cout<<ch;
    }
}

