#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>

#define MAX 256
#define MIN 32

void error_quit(char *msg){
    if(!!msg){
        printf("%s",msg);
    }
    exit(0);
}


int distill(char **opt, char **arg, char **origin){
    static char *options[MIN], *arguments[MIN];
    int optCount = 0, argCount = 0;
    for(int i = 0; origin[i] != NULL; i++){
        if
    }
}
