#include "headFile.h"
// functions and structures  {{{
    // structures and initialize function {{{
typedef struct _file_t {
    char *file;
    int fdout;
    int *flag;
    sem_t sema;
    pthread_mutex_t lock;
} file_t;

file_t allFile;

typedef struct _rangeComp_t {
    int base;
    int bound;
    int threadID;
} rangeComp_t;

void init(file_t *f, char *file, int fdout, int *secucess){
    f->file = file;
    f->fdout = fdout;
    f->flag = secucess;
    sem_init(&f->sema, 0, 1);
    pthread_mutex_init(&f->lock, NULL);
}
    // report error and exit
void error_quit(char *msg){
    printf("%s",msg);
    exit(0);
} // }}}

    // caculate the zip file name and store it to nameBuff {{{
int getZipName(char *file, char *zipName){
    int startcpy = 0, endcpy = 0, len = strlen(file);
    printf("file : %s\n", file);
    for(int i = 0; i < len; i++){
        if (*(file + i) == '/') {
            startcpy = i + 1;
            continue;
        }
    }
    for (int i = startcpy; i < len; i++){
        if(*(file + i) == '.' || (i == len - 1)){
            endcpy = i;
            break;
        }
    }
    for (int i = startcpy, j = 0; i < endcpy; i++, j++){
        //printf("startcpy is %d, endcpy is %d, and c is %c\n",startcpy, endcpy,file[i]);
        zipName[j] = file[i];
        if ( i == endcpy - 1){
            zipName[j + 1] = '.';
            zipName[j + 2] = 'z';
        }
    }
    //printf("zip file : %s\n",zipName);
    return 2 + endcpy - startcpy;
} // }}}

// threads' compression process {{{
    // function of compression
void compress(char *file, char *buffer, int start, int end){
    for (int i = start, j = 0; i < end; i++){
        buffer[j++] = 'a';
    }
}
    // coalesces each thread's compression segment together
void combine(char *buffer, file_t *all, rangeComp_t *r){
    size_t size = (size_t) r->bound - r->base;
    if(r->threadID != 0 && all->flag[r->threadID - 1] == 0){
        sem_wait(&all->sema);
    }
    pthread_mutex_lock(&all->lock);
    write(all->fdout, buffer, size);
    all->flag[r->threadID] = 1;
    sem_post(&all->sema);
    pthread_mutex_unlock(&all->lock);
}
    // the working function of threads
void *worker(void *range){
    file_t *all = &allFile;
    rangeComp_t *r = range;
    int size = r->bound - r->base;
    char *buffer = malloc(sizeof(char)*size);
    printf("threads %d: compress file from %d to %d\n", r->threadID, r->base, r->base + r->bound);
    compress(all->file, buffer, r->base, r->bound);
    combine(buffer, all, r);
    free(buffer);
    return NULL;
} // }}}
// function and structure defination end }}}

int main(int argc, char *argv[]){
    int fdin,fdout,len,numcpu = get_nprocs(),nameLen;
    int secucess[numcpu];
    char *src, nameBuff[MIN];
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
    if((nameLen = getZipName(argv[1],nameBuff)) > 0){
        char *name = malloc(sizeof(char)*nameLen);
        strncpy(name, nameBuff, nameLen);
        printf("zip flie : %s\n", name);
        if ((fdout = open(name, O_RDWR|O_TRUNC|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)) < 0){
            error_quit("can not create file\n");
        }
        free(name);
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
    init(&allFile,src,fdout,secucess);
    len = strlen(src);
    pthread_t tid[numcpu];
    rangeComp_t range[numcpu];
    rangeComp_t *r;
    for(int i = 0, size = len / numcpu; i < numcpu; i++){
        // initialize a thread's workload
        range[i].base = size*i;
        range[i].bound = size;
        range[i].threadID = i;
        secucess[i] = 0;
        // last one range shoud have a extra remainder of bound
        if (i == numcpu - 1) range[i].bound += size % numcpu;
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
