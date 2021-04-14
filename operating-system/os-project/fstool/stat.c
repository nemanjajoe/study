#include "commonHead.h"

void error_quit(char *msg){
    if(!!msg){
        printf("%s",msg);
    }
    exit(0);
}

void printStat(struct stat *s){
    printf("Device ID: %u\n", s->st_dev);
}

int main(int argc, char *argv[]){
    if(argc < 2){ // check if program has arguments;
        error_quit("no file to check\n");
    }
    int fd;
    struct stat statBuff;
    for(int i = 1; i < argc; i++){
        if((fd = open(argv[i], O_RDONLY)) < 0){
            printf("can not open the file : %s\n",argv[i]);
            error_quit(NULL);
        }
        if(fstat(fd, statBuff) != 0){
            error_quit("system call fstat failed!\n");
        }
        printStat(statBuff);
    }
    return 1;
}
