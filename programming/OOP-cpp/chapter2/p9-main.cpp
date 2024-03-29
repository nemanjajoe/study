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

// Auxiliary functions {{{

// printMenu: string -> user output;
// puepose  : print the menu in format;
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

// mini helper function for Menu;
void addHelper(student_t &person){

    cout<<"input the name of this person: ";
    cin>>person.name;
    cout<<"name: "<<person.name<<endl;

    cout<<"input the age of this person : ";
    int age;
    cin>>age;
    cout<<"age: "<<age<<endl;
    while(age < 0 || age >= 200){
        cout<<endl;
        cout<<"age should not less than 0 or more than 200"<<endl;
        cout<<"input the age again: ";
        cin>>age;
        cout<<"age: "<<age<<endl;
    }
    person.age = age;

    cout<<"input the phone number of this person: ";
    cin>>person.phone;
    cout<<"phone: "<<person.phone<<endl;

    cout<<"input the E-mail of this person: ";
    cin>>person.E_mail;
    cout<<"E-mail: "<<person.E_mail<<endl;

    cout<<"input the address of this person: ";
    cin>>person.address;
    cout<<"address: "<<person.address<<endl;
}
bool add(Contact &contact){
    if(!contact.displayAll()){
        return false;
    }

    student_t person;
    addHelper(person);

    bool flag = true;
    char ch;
    while(flag){
        cout<<endl;
        cout<<"confirm information: are you sure all correct ? [y/n] : ";
        cin.get(ch);
        cout<<ch<<endl;
        ch = toupper(ch);
        if(ch == 'Y'){
            contact.add(person);
            flag = false;
        }else if(ch == 'N'){
            cout<<endl;
            cout<<"input again!"<<endl;
            addHelper(person);
        }
    }
}
void display(Contact &contact){
    contact.displayAll();
}
bool modify(Contact &contact){
    if(!contact.displayAll()){
        return false;
    }
    int recNum;
    student_t person;

    contact.displayAll();
    cout<<"which record you want to modify ? (note: input the record number)";
    while(cin>>recNum, !contact.modify(recNum)){
        cout<<"unvalid record, try again!"<<endl;
    }
}
bool find(Contact &contact){
    if(!contact.displayAll()){
        return false;
    }
    char name[21];
    cout<<"input the person's name: ";
    cin>>name;
    contact.find(name);
}
bool del(Contact &contact){
    if(!contact.displayAll()){
        return false;
    }
    int recNum;
    student_t person;

    cout<<"which record you want to delete ?(note: input the record number): ";
    while(cin>>recNum, !contact.deletePerson(recNum)){
        cout<<"unvalid record, try again!"<<endl;
    }
}
void open(Contact &contact){
    char fileName[128];
    cout<<"input the file you want to open: ";
    cin>>fileName;
    contact.open(fileName);
}
void help(){
    char ch;
    cout<<endl;
    cout<<"the exact functionality of each order (note: input the number) : ";
    cout<<endl;
    cout<<"1. add    : add records to file.";
    cout<<endl;
    cout<<"2. display: display all records of the file.";
    cout<<endl;
    cout<<"3. modify : modify any record in file.";
    cout<<endl;
    cout<<"4. find   : look up a student by name.";
    cout<<endl;
    cout<<"5. delete : delete a record of a student.";
    cout<<endl;
    cout<<"6. exit   : exit this program.";
    cout<<endl;
    cout<<"7. open   : open a new file to manipulate.";
    cout<<endl;
    cout<<"8. help   : display the help information.";
    cout<<endl;

    cout<<"press any key to continue"<<endl;
    cin.get(ch);
}

// getOrder: user input -> integer;
// purpose : get an order command from user;
int getOrder(){
    char ch;
    cin.get(ch);
    return ch - 48;
} // }}}

int main(){
    Contact contact;
    printMenu();
    while(1){
        switch(getOrder()){
            case 1: add(contact);
                    break;
            case 2: display(contact);
                    break;
            case 3: modify(contact);
                    break;
            case 4: find(contact);
                    break;
            case 5: del(contact);
                    break;
            case 6: contact.save(); // exit this program;
                    return 0;
                    break;
            case 7: open(contact);
                    break;
            case 8: help();
                    break;
            default: printMenu();
        }
    }
return 0;
}
