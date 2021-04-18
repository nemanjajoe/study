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

void printStat(struct stat *s){
    char *blank = "     ";
    printf("Device ID: %u%s",(unsigned int) s->st_dev, blank);
    printf("inode number: %u%s",(unsigned int) s->st_ino, blank);
    printf("file mode: %o\n",(unsigned int) s->st_mode);
    printf("hard links: %u%s",(unsigned int) s->st_nlink, blank);
    printf("user ID: %u%sgroup ID: %u\n",(unsigned int) s->st_uid, blank,(unsigned int) s->st_gid);
    printf("file size: %d%sfile blocks: %d\n",(int) s->st_size, blank,(int) s->st_blocks);
    printf("preferred I/O block size: %d\n",(int) s->st_blksize);
    printf("last access: %slast modified: %slast status: %s", ctime(&s->st_ctime), ctime(&s->st_mtime), ctime(&s->st_atime));
}


int distill(char ***opt, char ***arg, char **origin){
    static char *options[MIN], *arguments[MIN];
    for (int i = 0; i < MIN; i++){
        options[i] = NULL;
        arguments[i] = NULL;
    }
    int optCount = 0, argCount = 0;
    for(int i = 0; origin[i] != NULL && optCount < MIN && argCount < MIN; i++){
        //store options and the args of this option
        if(origin[i][0] == '-'){
            static char buffer[MIN];
            strcpy(buffer, origin[i]);
            options[optCount] = buffer;
            optCount++;
        }else {
            arguments[argCount] = origin[i];
            argCount++;
        }
    }
    *opt = options;
    *arg = arguments;
    return argCount;
}
