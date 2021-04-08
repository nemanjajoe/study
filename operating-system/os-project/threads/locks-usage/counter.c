#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<sys/time.h>
#define MAX 4

typedef struct __counter_t {
    int value,value2;
    int times;
    pthread_mutex_t lock;
} counter_t;

void *increment(void *c){
    counter_t *p = (counter_t *)c;
    pthread_mutex_lock(&p->lock);
    for(int i = 0, j = p->times; i < j; i++){
        p->value++;
    }
    pthread_mutex_unlock(&p->lock);
    return NULL;
}
void *decrement(void *c){
    counter_t *p = (counter_t *)c;
    pthread_mutex_lock(&p->lock);
    for(int i = 0, j = p->times; i < j; i++){
        p->value--;
    }
    pthread_mutex_unlock(&p->lock);
    return NULL;
}
void init(counter_t *c){
    c->value = 0;
    c->value2 = 0;
    pthread_mutex_init(&c->lock,NULL);
}
int get(counter_t *c){
    return c->value;
}

counter_t counter;

int main(int argc, char *argv[]){
// initailization of options you typed in
    struct timeval tv, tv2;
    struct timeval start_tv, start_tv2;
    double time = 0.0, time2 = 0.0;
    int num[MAX];
    char *name[MAX];
    for (int i = 0; i < MAX; i++){
        num[i] = 0;
        name[i] = NULL;
    }
    for(int i = 1, j = 0, z = 0; i < argc; i++){
        if(i%2==0){
            num[j] = atoi(argv[i]);
            j++;
        }else {
            name[z] = argv[i];
            z++;
        }
    }
    counter_t *prt = &counter;
    init(prt);
    pthread_t tid[2];
// initailization has done
// start creating threads with concerrency and timing

    gettimeofday(&start_tv,NULL);
    for (int i = 0, j = 0; name[i] != NULL;i++){
        printf("name is %s   num is %d\n",name[i],num[i]);
        prt->times = num[i];
        if(strcmp(name[i], "-inc") == 0){
             pthread_create(&tid[j++],NULL,increment,(void *)prt);
        }else if(strcmp(name[i],"-dec") == 0){
             pthread_create(&tid[j++],NULL,decrement,(void *)prt);
        }else {
             printf("we have no such option with '%s'\n",name[i]);
        }
    }
    for(int i = 0; i < 2; i++){
        pthread_join(tid[i],NULL);
    }
    gettimeofday(&tv,NULL);
    time = (tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec)/1000000.0;
// all threads has done its job and get the time usage
// print the counter and time usage
    pthread_mutex_lock(&prt->lock);
    printf("value is %d\n", prt->value);
    printf("time usage(threads) :%.6f \n",time);
    pthread_mutex_unlock(&prt->lock);

// test the time usage of normal counter;
    gettimeofday(&start_tv2,NULL);
    for (int i = 0; name[i] != NULL;i++){
        printf("name is %s   num is %d\n",name[i],num[i]);
        prt->times = num[i];
        if(strcmp(name[i], "-inc") == 0){
            for(int t = prt->times; t > 0 ; t--){
                prt->value2++;
            }
        }else if(strcmp(name[i],"-dec") == 0){
            for(int t = prt->times; t > 0 ; t--){
                    prt->value2--;
            }
        }else {
             printf("we have no such option with '%s'\n",name[i]);
        }
    }
    gettimeofday(&tv2,NULL);
    time2 = (tv2.tv_sec - start_tv2.tv_sec) + (tv2.tv_usec - start_tv2.tv_usec)/1000000.0;
// test over and print the consequence
    printf("value 2 is %d\n", prt->value2);
    printf("time usage(normal counter) :%.6f \n",time2);
    pthread_exit(NULL);
return 1;
}

