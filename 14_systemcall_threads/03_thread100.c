/*
    thread 100개를 생성하라.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
# define NUM_THREADS 100

void* myfunc(void* arg) {
    printf("Thread created\n");
    pthread_exit(NULL);
}
int main(void){

    pthread_t mythread[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&mythread[i], NULL, myfunc, NULL);
    }
    printf("I am a main thread\n");
    
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(mythread[i], NULL);
    }

    return 0;
}