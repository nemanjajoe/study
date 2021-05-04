#include "p9-class.h"

using namespace std;

// Auxiliary functions of this Contact; {{{

// getCounts: fstream -> integer
// purpose: calculate how many records are in this file
int getCounts(fstream &file){
    int counts = 0;
    student_t person;
    while(!file.eof()){
        file.read((char *) &person, sizeof(person));
        //showInfo(person);
        counts++;
    }
    file.clear();
    return counts - 1;
}

// createFile: string -> none
// purpose: create a file with the file name
void createFile(char* name){
    ofstream file(name);
    if(file.fail()){
        cout<<"can't create file: "<<name<<endl;
        exit(0);
    }
    file.close();
}

// getByte: int -> long
// purpose: calculate how many bytes to read from for a student
long getByte(int recNum){
    return sizeof(student_t)*recNum;
}

// showInfo: student_t -> none
// purpose: display one student's all information
extern void showInfo(student_t &person){
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
        }
        cout<<"continue modify? [y/n?]: ";
        cin.get(ch);
        ch = toupper(ch);
        while(ch != 'Y' && ch != 'N'){
            cout<<endl;
            cout<<"unexpect manipulator: "<<ch<<endl;
            cout<<"continue modify? [y/n?]: ";
            cin.get(ch);
            ch = toupper(ch);
        }
        if(ch == 'Y'){
            continue;
        }
        flag = false;
    }
} //}}}

// Contact member functions' implementation

bool Contact::add(student_t &student){
    if(!this->hasFile){
        cout<<"no file was opened, please open a file first!!"<<endl;
        return false;
    }
    file.write((char *) &student, sizeof(student));
    this->count++;
    cout<<"student "<<student.name<<" was added to this contact"<<endl;
    return true;
}

bool Contact::displayAll(){
    if(!this->hasFile){
        cout<<"no file was opened, please open a file first!!"<<endl;
        return false;
    }
    student_t person;
    for(int i = 0; i < this->count; i++){
        this->file.seekg(getByte(i), ios::beg);
        this->file.read((char *) &person, sizeof(person));
        cout<<"the "<< i <<"th record:"<<endl;
        showInfo(person);
        cout<<endl;
    }
    return true;
}

bool Contact::modify(int recNum){
    if(!this->hasFile){
        cout<<"no file was opened, please open a file first!!"<<endl;
        return false;
    }
    student_t person;

    if(recNum < 0 || recNum >= this->count){
        return false;
    }

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
    return true;
}

bool Contact::find(char* name){
    if(!this->hasFile){
        cout<<"no file was opened, please open a file first!!"<<endl;
        return false;
    }
    student_t person;
    for(int i = 0; i < this->count; i++){
        this->file.seekg(getByte(i), ios::beg);
        this->file.read((char *) &person, sizeof(person));
        if(strcmp(person.name, name) == 0){
            cout<<"the "<<name<<"'s information:"<<endl;
            showInfo(person);
            return true;
        }
    }
    cout<<"can't find student: "<<name<<endl;
    return false;
}

bool Contact::deletePerson(int recNum){
    if(!this->hasFile){
        cout<<"no file was opened, please open a file first!!"<<endl;
        return false;
    }
    if(recNum < 0 || recNum >= this->count){
        return false;
    }

    char tempFileName[] = "temp.dat";
    createFile(tempFileName);
    fstream tempFile(tempFileName, ios::out);
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
            ch = toupper(ch);
            while(ch != 'Y' && ch != 'N'){
                cout<<"unexpect manipulator: "<<ch<<endl;
                cout<<"please input again!"<<endl;
                showInfo(person);
                cin.get(ch);
                ch = toupper(ch);
            }
            if(ch == 'Y'){
                continue;
            }
        }
        tempFile.write((char *) &person, sizeof(person));
    }
    tempFile.close();
    this->save();
    remove(this->fileName);
    rename(tempFileName,this->fileName);
    this->open(this->fileName);
    return true;
}

// save: none
// purpose: clear status and close file;
void Contact::save(){
    if(this->hasFile){
        this->hasFile = false;
        this->count = 0;
        this->file.close();
    }
}

bool Contact::open(char* fName){
    strcpy(this->fileName, fName);

    this->save();
    this->file.open(this->fileName, ios::in | ios::out);
    if(this->file.fail()){
        cout<<"can't open file(p9-class.cpp : Contact::open ): "<<this->fileName<<endl;
        return false;
    }

    this->count = getCounts(this->file);
    cout<<endl<<"the count is : "<<this->count<<endl;
    this->hasFile = true;
    this->displayAll();
    return true;
}

// test:
// purpose: test if all functions are correct;
void Contact::test(){
    char testFileName[] = "testFile.dat";
    createFile(testFileName);

    student_t person[4] = {
        {"Jesson Ben" , 21, "898-1234-123", "Jesson@mail.com" , "hnust, hunan, china"         },
        {"Abelson Joe", 34, "796-3324-846", "Abelson@mail.com", "alber, locky, United Kingdom"},
        {"Jay Sussman", 32, "976-4215-643", "Sussman@mail.com", "northy, wortkey, singapore"  },
        {"Alan Yayger", 23, "897-5523-667", "Yayger@mail.com" , "orsaypho, norman, frence"    }
    };

    this->open(testFileName);

    for(int i = 0; i < 4; i++){
        cout<<"testing add and display function ...."<<endl;
        sleep(0.6);
        this->add(person[i]);
        cout<<endl;
        this->displayAll();
        sleep(0.6);
    }

    cout<<"testing find function ...."<<endl;
    sleep(0.6);
    this->find(person[2].name);
    cout<<endl;

    cout<<"testing delete function ...."<<endl;
    cout<<"deleting record 2"<<endl;
    sleep(0.6);
    cout<<"deleting ...."<<endl;
    //this->deletePerson(2);
    this->displayAll();

    cout<<"testing over ..."<<endl;
    this->save();
}
