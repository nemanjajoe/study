#include <stdio.h>
#include "common_threads.h"

int balance = 0;
// pthread_mutex_t lock;
void* worker(void* arg) {
   // pthread_mutex_lock(&lock);
    balance++; // unprotected access
    printf("balance is %d\n",balance);
   // pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    pthread_t *prt = &p;
    Pthread_create(prt, NULL, worker, NULL);
    // balance++; // unprotected access
    Pthread_join(p, NULL);
    return 0;
}
