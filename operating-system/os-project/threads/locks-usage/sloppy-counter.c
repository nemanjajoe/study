#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<sys/time.h>
#define NUMCPU 4
// structure defination {{{
typedef struct __counter_t {
    int global;
    pthread_mutex_t glock;
    int local[NUMCPU];
    pthread_mutex_t llock[NUMCPU];
    int threshold;
} counter_t;

typedef struct __thread_t {
    int tid;
    int times;
} thread_t;  // structure defination done  }}}

// function's defination {{{
void init(counter_t *c, int threshold){
    c->global = 0;
    pthread_mutex_init(&c->glock,NULL);
    for (int i = 0; i < NUMCPU; i++){
        c->local[i] = 0;
        pthread_mutex_init(&c->llock[i],NULL);
    }
    c->threshold = threshold;
}

void increment(counter_t *c, int tid){
    pthread_mutex_lock(&c->llock[tid]);
    c->local[tid]++;
    pthread_mutex_unlock(&c->llock[tid]);
}

void update(counter_t *c, int tid){
    pthread_mutex_lock(&c->glock);
    c->local[tid]++;
    if(c->local[tid] > c->threshold){
        c->global += c->local[tid];
        c->local[tid] = 0;
    }
    pthread_mutex_unlock(&c->glock);
}
int get(counter_t *c){
    int val;
    pthread_mutex_lock(&c->glock);
    val = c->global;
    pthread_mutex_unlock(&c->glock);
    return val;
} // }}}

counter_t counter;
counter_t counter2;

void *worker(void *thd){
    thread_t *t = (thread_t *)thd;
    int loops = t->times;
    int tid = t->tid;
    for (int i = 0; i < loops; i++){
        update(&counter, tid);
    }
    return NULL;
}

int main(int argc, char *argv[]){
    struct timeval tv, tv2;
    struct timeval start_tv, start_tv2;
    double time = 0.0, time2 = 0.0;
    int timesOfThread = atoi(argv[1]);
    int timesOfProcess = timesOfThread*NUMCPU;
    int threshold = atoi(argv[2]);
    pthread_t tid[NUMCPU];
    thread_t t[NUMCPU];
    init(&counter, threshold);
    init(&counter2, threshold);
    // start counting time usage by threads {{{
    gettimeofday(&start_tv,NULL);
    for(int i = 0; i < NUMCPU; i++){
        thread_t *pt = &t[i];
        pt->tid = i;
        pt->times = timesOfThread;
        pthread_create(&tid[i],NULL,worker,(void *) pt);
    }
    for (int i = 0; i < NUMCPU; i++){
        pthread_join(tid[i],NULL);
    }
    gettimeofday(&tv,NULL);
   // end counting time usage by threads }}}
    time = (tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec)/1000000.0;
    printf("global value is %d, time usage by threads is %.6f\n",get(&counter),time);
   // start counting time usage by process {{{
    gettimeofday(&start_tv2,NULL);
    for (int i = 0; i < timesOfProcess; i++){
        counter2.global++;
    }
    gettimeofday(&tv2,NULL);
  // end counting time usage by process }}}
    time2 = (tv2.tv_sec - start_tv2.tv_sec) + (tv2.tv_usec - start_tv2.tv_usec)/1000000.0;
    printf("global value is %d, time usage by process is %.6f\n",counter2.global,time2);

}
