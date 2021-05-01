#include "file.h"

using namespace std;

int main(){
    fstream file("file.h", ios::in);
    //openFileIn(file);
    file.close();
return 0;
}
