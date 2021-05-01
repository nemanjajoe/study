#include<iostream>
#include<iomanip>
#include<fstream>

#define MAX 128

using namespace std;

void openFileIn(fstream &file){
    char name[MAX];
    cin>>name;
    file.open(name);
    while(file.fail()){
        cout<<"input file again!"<<endl;
        cin>>name;
        file.open(name, ios::in);
    }
}
