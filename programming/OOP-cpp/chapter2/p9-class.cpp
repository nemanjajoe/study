#include "p9-class.h"

using namespace std;

// Auxiliary functions of this Contact;

// getByte: int -> long
// purpose: calculate how many bytes to read from for a student
long getByte(int recNum){
    return sizeof(student_t)*recNum;
}
// showInfo: student_t -> none
// purpose: display one student's all information
void showInfo(student_t &person){
    cout<<"name    :";
    cout<<person.name<<endl;
    cout<<"age     :";
    cout<<person.age<<endl;
    cout<<"phone   :";
    cout<<person.phone<<endl;
    cout<<"E-mial  :";
    cout<<person.E-mail<<endl;
    cout<<"address :";
    cout<<person.address<<endl;
}
// modifyInfo: student -> none
// purpose: modify a student's information
   // auxiliary functions of modifyIndo
   // modName   : student_t -> string
    char* modName(student_t &person){}
   // modAge    : student_t -> string

   // modPhone  : student_t -> string

   // modE-mail : student_t -> string

   // modAddress: student_t -> string
void modifyInfo(student_t &person){
    bool flag = true;
    int modIndex, ch;
    while(flag){
        cout<<"which part you want to modify ?"<<endl;
        cout<<"1. name   "<<setw(5);
        cout<<"2. age    "<<setw(5);
        cout<<"3. phone  "<<setw(5);
        cout<<"4. E-mail "<<setw(5);
        cout<<"5. address"<<setw(5)<<endl;
        cin>>modIndex;
        switch(modIndex){
            case 1 : cout<<modName(person)   <<endl;
                     break;
            case 2 : cout<<modAge(person)    <<endl;
                     break;
            case 3 : cout<<modPhone(person)  <<endl;
                     break;
            case 4 : cout<<modE-mail(person) <<endl;
                     break;
            case 5 : cout<<modAddress(person)<<endl;
                     break;
            default: cout<<"unexpected manipulation, try again!"<<endl;
                     continue;
        }
        cout<<"continue modify? (y/n): ";
        if(toupper(cin.get(ch)) == 'Y'){
            continue;
        }
        flag = false;
    }
}


// Contact member functions' implementation
void Contact::add(student_t &student){
    file.write((char *) student, sizeof(student));
    this->count++;
    cout<<"student "<<student.name<<" was added to this contact"<<endl;
}

void Contact::display(){
    student_t person;
    for(int i = 0; i < this->count; i++){
        this->file.seekg(getByte(i), ios::beg);
        this->file.read((char *) &person, sizeof(person))
        cout<<"the "<< i + 1 <<"th record:"<<endl;
        showInfo(person);
        cout<<endl;
    }
}

void Contact::modify(int recNum){
    student_t person;

    this->file.seekg(getByte(recNum), ios::beg);
    this->file.read((char *) &person, sizeof(person));
    cout<<"before modified: "<<endl;
    showInfo(person);
    cout<<endl;
    modifyInfo(person);

    this->file.seekg(getByte(recNum), ios::beg);
    this->file.write((char *) &person, sizeof(person));
    cout<<"after modified: "<<endl;
    showInfo(person);
}
