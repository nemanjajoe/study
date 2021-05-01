#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#include<fstream>

#define MAX 128

using namespace std;

// purpose: open an input file
void getInput(ifstream &file){
    char name[MAX];
    cout<<"which file you want to encrypt ? (note: input file name)"<<endl;
    cin>>name;
    file.open(name);
    while(file.fail()){
        cout<<"can't open file: "<<name<<endl<<" please input again!"<<endl;
        cin>>name;
        file.open(name);
    }
}
// purpose: create an output file
void createOutput(ofstream &file){
    char name[MAX];
    cout<<"input encryption file name: ";
    cin>>name;
    file.open(name);
    if(file.fail()){
        cout<<"can't create output file!"<<endl;
        exit(0);
    }
}
// purpose: encrypt the input file to output file
void encrypt(ifstream &input, ofstream &output){
    char ch;
    while(!input.eof()){
        input.get(ch);
        ch += 2;
        output.put(ch);
    }
}
