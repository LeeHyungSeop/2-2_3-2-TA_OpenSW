/*
    thread 2개를 생성하여,
    각각 global variable cnt값을 5,000씩 증가시켜
    최종 10,000이 되도록 하라.
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_THREADS 2
#define NUM_INCREMENTS 50000

volatile static long long cnt = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex 초기화

void* worker(void* args) {
    for (int i = 0; i < NUM_INCREMENTS; i++){
        pthread_mutex_lock(&mutex); // mutex lock
        cnt += 1;
        pthread_mutex_unlock(&mutex); // mutex unlock
    }
    pthread_exit(NULL);
}
int main(void){

    pthread_t mythread[NUM_THREADS];
    int result;

    for (int i = 0; i < NUM_THREADS; i++) {
        result = pthread_create(&mythread[i], NULL, worker, NULL);
        assert(result == 0);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        result = pthread_join(mythread[i], NULL);
        assert(result == 0);
    }
    printf("final value of cnt = %lld\n", cnt);

    return 0;
}