#include "class.h"

using namespace std;

int main(){
    char name[] = "mian.cpp";
    fstream file(name);
    Dog magic(name);
    magic.eat();
    magic.bark();
return 0;
}
