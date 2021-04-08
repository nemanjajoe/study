#include <stdio.h>

#include "common_threads.h"

int done = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // new line 

void* worker(void* arg) {
    Pthread_mutex_lock(&lock); // new
    printf("this should print first\n");
    done = 1;
    Pthread_mutex_unlock(&lock); // new
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);
    Pthread_mutex_lock(&lock);
    while (done == 0)
	;
    Pthread_mutex_unlock(&lock);
    printf("this should print last\n");
    return 0;
}
