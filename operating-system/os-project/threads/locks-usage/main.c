#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"common_threads.h"
#define MAX 128
 // all structs {{{
typedef struct __threads_t {
    char name[MAX];
    int num;
    struct __threads_t *next;
} threads_t;
// }}}

void init(counter_t *c){
    c->value = 0;
}
threads_t head;  // creat a linked list to store all the threads and their execution times.

// main function {{{
int main(int argc,char *argv[]) {
    struct timeval tv;
    struct timeval start_tv;
    double time = 0.0;

    head.name = argv[0];
    head.num = 0;
    threads_t *current = &head;
    for(int i = 1; i < argc; i++){
        if(i%2 == 1){
            threads_t *new = malloc(sizeof(threads_t));
            current->next = new;
            current = new;
            current->name = argv[i];
        }else {
            current->num = atoi(argv[i]);
        }
    }

    gettimeofday(&start_tv,NULL);  // start timing
    counter_t counter;
    counter_t *prt = &counter;
    init(&counter);
    for (current = head.next;current != NULL;current = current->next) {
        char *threadName = current->name;
        int loops = current->num;
        pthread_t tid;
        while(loops){
            if(strcmp(threadName,"-inc") == 0){
                Pthread_create(&tid,NULL,increment,(void *) prt);
               // printf("counter is %d\n",prt->value);
                Pthread_join(tid,NULL);
            }else if(strcmp(threadName,"-dec") == 0){
                Pthread_create(&tid,NULL,decrement,(void *) prt);
                Pthread_join(tid,NULL);
            }
            loops--;
        }
    }
    gettimeofday(&tv,NULL);       // end clocking
    time = (tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec)/1000000.0;
    printf("time usage :%.6f \n counter: %d\n",time,counter.value);
    return 0;
}  // }}}


