//************************************************************************
//* program auther: NemanjaJoe
//* date: May 2th, 2021
//* chapter: 2
//* quiz index: 9
//* description : student contact program.
//*               program store the information below to files:
//*                  >>name    : an array has 21 chars.
//*                  >>age     : an integer variable.
//*                  >>address : an array has 51 chars.
//*                  >>phone   : an array has 14 chars.
//*                  >>E-mail  : an array has 51 chars.
//* requirements: this program has a menu that eables user to take below manipulation:
//*                  1. add    : enable to add records to file.
//*                  2. display: enable to display all records of the file.
//*                  3. modify : enable to modify any record in file.
//*                  4. find   : enable to look up a student by name.
//*                  5. delete : enable to delete a record of a student.
//*                  6. exit   : exit this program;
//*                  7. open   : open a new file to manipulate;
//*                  8. help   : display the help information;
//************************************************************************

#include "p9-class.h"

using namespace std;

void printMenu(){
    char blank[] = "     ";
    cout<<"Menu:"<<endl;
    cout<<blank<<"1. add         ";
    cout<<blank<<"2. display     ";
    cout<<blank<<"3. modify      ";
    cout<<blank<<"4. find        ";
    cout<<endl;
    cout<<blank<<"5. delete      ";
    cout<<blank<<"6. exit        ";
    cout<<blank<<"7. open        ";
    cout<<blank<<"8. help        ";
    cout<<endl;
}

int getOrder(){
    char ch;
    cin.get(ch);
    return ch - 48;
}

int main(){
    Contact contact;
    while(1){
        printMenu();
        if(getOrder() == 6){
            return 0;
        }
    }
return 0;
}
