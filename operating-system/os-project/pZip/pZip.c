#include "headFile.h"

// function and structure defination {{{
    // define a struct that stands for the range of a file a thread should compress
typedef struct _rangeComp_t {
    char *target;
    int base;
    int bound;
    int threadID;
} rangeComp_t;
    // report error and exit
void error_quit(char *msg){
    printf("%s",msg);
    exit(0);
}
    // get the file name and convert it to the zip file name
char *getZipName(char *file){/*{{{*/
    char name[MIN];
    char *zipName = name;
    printf("file : %s\n", file);
    for(int i = 0, len = strlen(file); i < len; i++){
                // debug: printf("%c\n",file[i]);
            if(*(file + i) == '/') continue;
            if((*(file + i) == '.') || (i == len)){
                strncpy(zipName,file,i);
                strcat(zipName,".z");
                printf("zip file : %s\n",zipName);
                break;
            }
        }
    return zipName;
}/*}}}*/
    // threads' functionality of compression. in other words, the compression function
void compress(char *target, int base, int bound){

}
    // threads' functionaliy of combination that coalesces the thread's compression
void combine(){

}
    // the working function of threads
void *worker(void *range){
    rangeComp_t *r = (rangeComp_t *) range;
    printf("threads %d: compress file from %d to %d\n", r->threadID, r->base, r->base + r->bound);
    return NULL;
}
// function and structure defination end }}}

int main(int argc, char *argv[]){
    int fdin,fdout,len,numcpu = get_nprocs();
    char *src, *dest;
    struct stat statbuff;
    // prerequisites and checks for all the subsequent process {{{
    if (argc < 2) {
        error_quit("no file to print\n");
    }
        // open the input file
    if((fdin = open(argv[1],O_RDONLY)) < 0){
        error_quit("can not open the file!\n");
    }
        // create a file used to store compressed data
    if((fdout = open(dest = getZipName(argv[1]), O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IRGRP|S_IROTH)) < 0){
        error_quit("can not create file\n");
    }
        //get the state of the input file
    if(fstat(fdin,&statbuff) < 0){
        error_quit("find stat error\n");
    }
        // map the input file to src
    if((src = mmap(0,statbuff.st_size,PROT_READ,MAP_SHARED,fdin,0)) == (caddr_t) -1){
        error_quit("map file error\n");
    }
    // }}}
    // create threads and start compression process {{{
    len = strlen(src);
    pthread_t tid[numcpu];
    rangeComp_t range[numcpu], *r;
    for(int i = 0, size = len / numcpu; i < numcpu; i++){
        range[i].target = src;
        range[i].base = size*i;
        range[i].bound = size;
        range[i].threadID = i;
        // last one range shoud have a extra remainder of bound
        if (i == 3) range[i].bound += size % numcpu;
        r = &range[i];
        if(pthread_create(&tid[i],NULL,worker, (void *) r) != 0){
            error_quit("thread creation failed\n");
        }
    }
    for(int i = 0; i < numcpu; i++){
        if(pthread_join(tid[i],NULL) != 0){
            error_quit("thread join failed\n");
        }
    }
    // }}}
    return 1;
}
