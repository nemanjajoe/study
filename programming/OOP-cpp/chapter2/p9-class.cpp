#include "p9-class.h"

using namespace std;

// Auxiliary functions of this Contact; {{{

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
    cout<<person.E_mail<<endl;
    cout<<"address :";
    cout<<person.address<<endl;
}

// modifyInfo: student -> none
// purpose: modify a student's information
   // modName   : student_t -> string
    char* modName(student_t &person){
        char newName[21];
        cout<<"input the new name: ";
        cin>>newName;
        strcpy(person.name, newName);
        return person.name;
    }
   // modAge    : student_t -> integer
    int modAge(student_t &person){
        int newAge;
        cout<<"input the new age: ";
        while((cin>>newAge) < 0 || newAge > 200) {
            cout<<"no such age '"<<newAge<<"' try again!"<<endl;
        };
        person.age = newAge;
        return person.age;
    }
   // modPhone  : student_t -> string
    char* modPhone(student_t &person){
        char newPhone[14];
        cout<<"input the new phone number: ";
        cin>>newPhone;
        strcpy(person.phone, newPhone);
        return person.phone;
    }
   // modE_mail : student_t -> string
    char* modE_mail(student_t &person){
        char newE_mail[51];
        cout<<"input new E_mail address: ";
        cin>>newE_mail;
        strcpy(person.E_mail, newE_mail);
        return person.E_mail;
    }
   // modAddress: student_t -> string
    char* modAddress(student_t &person){
        char newAddress[51];
        cout<<"input new address: ";
        cin>>newAddress;
        strcpy(person.address, newAddress);
        return person.address;
    }
void modifyInfo(student_t &person){
    bool flag = true;
    int modIndex;
    char ch, blank[] = "     ";
    while(flag){
        cout<<"which part you want to modify ?"<<endl;
        cout<<blank<<"1. name   "<<blank;
        cout<<blank<<"2. age    "<<blank;
        cout<<blank<<"3. phone  "<<blank;
        cout<<blank<<"4. E_mail "<<blank;
        cout<<blank<<"5. address"<<blank;
        cout<<endl;
        cin>>modIndex;
        switch(modIndex){
            case 1 : cout<<modName(person)   <<endl;
                     break;
            case 2 : cout<<modAge(person)    <<endl;
                     break;
            case 3 : cout<<modPhone(person)  <<endl;
                     break;
            case 4 : cout<<modE_mail(person) <<endl;
                     break;
            case 5 : cout<<modAddress(person)<<endl;
                     break;
            default: cout<<"unexpected manipulation, try again!"<<endl;
                     continue;
        }
        cout<<"continue modify? [y/n?]: ";
        cin.get(ch);
        while(toupper(ch) != 'Y' || ch != 'N'){
            cout<<"unexpect manipulator: "<<ch<<endl;
            cout<<"'y' for yes , 'n' for no to continue modify"<<endl;
            cout<<"please input again!"<<endl;
            cout<<"continue modify? [y/n?]: ";
            cin.get(ch);
        }
        if(ch == 'Y'){
            continue;
        }
        flag = false;
    }
} //}}}


// Contact member functions' implementation
void Contact::add(student_t &student){
    file.write((char *) &student, sizeof(student));
    this->count++;
    cout<<"student "<<student.name<<" was added to this contact"<<endl;
}

void Contact::displayAll(){
    student_t person;
    for(int i = 0; i < this->count; i++){
        this->file.seekg(getByte(i), ios::beg);
        this->file.read((char *) &person, sizeof(person));
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

void Contact::find(char* name){
    student_t person;
    for(int i = 0; i < this->count; i++){
        this->file.seekg(getByte(i), ios::beg);
        this->file.read((char *) &person, sizeof(person));
        if(strcmp(person.name, name) == 0){
            cout<<"the "<<name<<"'s information:"<<endl;
            showInfo(person);
        }
    }
    cout<<"can't find student: "<<name<<endl;
}

void Contact::deletePerson(int recNum){
    fstream tempFile("temp.dat", ios::out);
    if(tempFile.fail()){
        cout<<"create temporary file failed"<<endl;
        exit(0);
    }

    student_t person;
    bool flag = true;
    char ch;
    for(int i = 0; i < this->count; i++){
        this->file.seekg(getByte(i), ios::beg);
        this->file.read((char *) &person, sizeof(person));
        if(i == recNum){
            cout<<"are you sure to delete the student irrevocably [y/n?]"<<endl;
            showInfo(person);
            cin.get(ch);
            while(toupper(ch) != 'Y' || ch != 'N'){
                cout<<"unexpect manipulator: "<<ch<<endl;
                cout<<"'y' for yes , 'n' for no to continue modify"<<endl;
                cout<<"please input again!"<<endl;
                cout<<"are you sure to delete the student irrevocably [y/n?]"<<endl;
                showInfo(person);
                cin.get(ch);
            }
            if(ch == 'Y'){
                continue;
            }
        }
        tempFile.write((char *) &person, sizeof(person));
    }
    remove(this->fileName);
    rename("temp.dat",fileName);
    this->file.open(this->fileName);
    this->count--;
}
