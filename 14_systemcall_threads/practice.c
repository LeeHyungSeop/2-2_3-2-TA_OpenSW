#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 100

volatile long long counter = 0;
volatile char is_running = 1;

void* start_routine(void* arg){
    while(is_running){
        counter++;
    }
    pthread_exit(NULL);
}

int main(void){

    pthread_t mythread[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&mythread[i], NULL, start_routine, &i);
    }
    
    for (int i = 0; i < 5; i++){
        sleep(1);
        printf("counter: %lld\n", counter);
    }
    
    is_running = 0;

    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(mythread[i], NULL);
    }
    
    

    return 0;
}