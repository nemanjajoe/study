#include "commonHead.h"

void printdir(DIR *dir){
    struct dirent *d;
    while((d = readdir(dir)) != NULL){
        printf("%lu %s\n", (unsigned long) d->d_ino, d->d_name);
    }
}

int main(int argc, char *argv[]){
    char *buffer = malloc(sizeof(char)*MAX);
    char *cwdir;
    DIR *currentdir;
    if (argc < 2){
        cwdir = getcwd(buffer, (size_t) MAX);
        currentdir = opendir(cwdir);
        printdir(currentdir);
    }else {
        for(int i = 1; i < argc; i++){
            if((currentdir = opendir(argv[i])) == NULL){
                printf("%s is not a directory\n", argv[i]);
                continue;
            }
            printdir(currentdir);
        }
    }
    //closedir(currentdir);
    free(buffer);
return 0;
}
