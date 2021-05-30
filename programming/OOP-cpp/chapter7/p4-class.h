#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef _FREEARRAY_
#define _FREEARRAY_

template <typename T>
class FreeArray{
    private:
        T * ap;
        int length;
        void memError(void);
        void subError(void);
    public:
        FreeArray(void);
        FreeArray(int);
        FreeArray(const FreeArray &);
        ~FreeArray();

        int getLength(void);
        T &operator[](const int &);
        void operator=(const FreeArray &);
};

template <typename T>
void FreeArray <T> ::memError(void){
    cout<<"error: memory manipulation failed"<<endl;
    exit(0);
}

template <typename T>
void FreeArray <T> ::subError(void){
    cout<<"error: subscript out of valid range"<<endl;
    exit(0);
}

template <typename T>
FreeArray <T> ::FreeArray(void){
    ap = NULL;
    length = 0;
}

template <typename T>
FreeArray <T> ::FreeArray(int l){
    length = l;
    ap = new T [l];
    if(ap == 0) memError();
    for(int i = 0; i < length; i++){
        ap[i] = 0;
    }
}

template <typename T>
FreeArray <T> ::FreeArray(const FreeArray &obj){
    int len = obj.length;
    this->length = len;
    ap = new T [len];
    if(ap == 0) memError();
    for(int i = 0; i < len; i++){
        *(ap + i) = *(obj.ap + i);
    }
}

template <typename T>
FreeArray <T> ::~FreeArray(){
    if(ap != NULL) delete [] ap;
}

template <typename T>
int FreeArray <T> ::getLength(void){
    return this->length;
}

template <typename T>
T &FreeArray <T> ::operator[](const int &i){
    if(i < 0 || i >= length) subError();
    return this->ap[i];
}

template <typename T>
void FreeArray <T> ::operator=(const FreeArray &obj){
    int len = obj.length;
    this->length = len;
    ap = new T [len];
    for (int i = 0; i < len; i++){
        ap[i] = *(obj.ap + i);
    }
}
#endif

#ifndef _SEARCHARRAY_
#define _SEARCHARRAY_

template <typename T>
class SearchArray: public FreeArray <T>{
    public:
        SearchArray(){};
        SearchArray(int s):FreeArray<T> (s){};
        SearchArray(SearchArray &obj) :FreeArray<T> (obj.getLength()){
            int len = this->getLength();
            for(int i = 0; i < len; i++){
                this->operator[](i) = obj[i];
            }
        };
        SearchArray(const FreeArray<T> &obj):FreeArray<T> (obj){};
        ~SearchArray(){};
        int find(T);
};

template <typename T>
int SearchArray<T>::find(T){
    return 0;
}

#endif

