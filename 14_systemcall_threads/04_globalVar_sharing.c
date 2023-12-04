/*
    long long type의 global variable counter = 0
    char type의 global variable is_running = 1

    is_running == 1 동안, loop를 돌면서 counter값 증가
    is_running == 0인 경우, loop를 종료하고 thread 종료

    main thread는
    sleep(1)을 사용하여 1초마다 한번씩 counter값 출력.
    10회 loop를 돌고 나면, is_running = 0으로 변경.
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 100

static long long counter = 0;
static char is_running = 1;

void *myfunc(void *arg) {
    while(is_running) {
        counter++;
    }
    pthread_exit(NULL);
}

int main(void){
    pthread_t mythread[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&mythread[i], NULL, myfunc, NULL);
    }
    for (int i = 0; i < 10; i++){
        sleep(1);
        printf("counter = %lld\n", counter);
    }
    is_running = 0;

    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(mythread[i], NULL);
    }
    return 0;
}