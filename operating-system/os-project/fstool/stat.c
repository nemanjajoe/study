#include "commonHead.h"

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
        if(fstat(fd, &statBuff) != 0){
            error_quit("system call fstat failed!\n");
        }
        printStat(&statBuff);
    }
    return 1;
}
