//************************************************************************
//* program auther: NemanjaJoe
//* date: May 1th, 2021
//* chapter: 2
//* quiz index: 7
//* description: write a file encryption program, which can encrypt every charactor of
//*              input file in some way to the output file.
//*              although there are lots of encryption algorithms out of online
//*              you can select one as simple as possible. for example, one that
//*              increments ASCII value by 2 for every charactor.
//************************************************************************

#include "p7-header.h"

using namespace std;

int main(){
    //get input file and create output file
    ifstream inputFile;
    ofstream outputFile;
    getInput(inputFile);
    createOutput(outputFile);
    //encrypt input file and put them to output file
    encrypt(inputFile, outputFile);
    inputFile.close();
    outputFile.close();
return 0;
}
