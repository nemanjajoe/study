#include "commonHead.h"

void printdir(DIR *dir, char **options, int index){
    struct dirent *d;
    while((d = readdir(dir)) != NULL){
        if((options[index] != NULL) && (strcmp(options[index], "-l") == 0)){
            int fd;
            struct stat statBuff;
            if((fd = open(d->d_name, O_RDONLY)) < 0){
                printf("can not open the file : %s\n",d->d_name);
                error_quit(NULL);
            }
            if(fstat(fd, &statBuff) != 0){
                error_quit("system call fstat failed!\n");
            }
            printf("\n      file %s \n", d->d_name);
            printStat(&statBuff);
        }else
            printf("%lu %s\n", (unsigned long) d->d_ino, d->d_name);
    }
}

int main(int argc, char *argv[]){
    char *buffer = malloc(sizeof(char)*MAX);
    char *cwdir, **opts, **args;
    DIR *currentdir;
    int numargs = distill(&opts, &args, argv);
    if (argc < 2){
        cwdir = getcwd(buffer, (size_t) MAX);
        currentdir = opendir(cwdir);
        printdir(currentdir, opts, 0);
    }else {
        for(int i = 1; i < numargs; i++){
            if((currentdir = opendir(args[i])) == NULL){
                printf("%s is not a directory\n", argv[i]);
                continue;
            }
            printf("directory %s\n", args[i]);
            printdir(currentdir, opts, i - 1);
            printf("\n");
        }
    }
    //closedir(currentdir);
    free(buffer);
return 0;
}
