#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

/*
    myfunc() 함수를 실행하는 thread를 생성하라.
*/

void* myfunc(void* arg) {
    printf("Thread created\n");
    pthread_exit(NULL);
}

int main(void) {

    pthread_t mythread;
    int result = pthread_create(&mythread, NULL, myfunc, NULL);
    if(result) { // On success, pthread_create() returns 0; on error
        printf("pthread_create() error code: %d\n", result);
        exit(1); // error
    }

    printf("I am a main thread\n");
    pthread_exit(NULL); // main thread만 종료. 나머지 thread는 계속 실행.

    return 0;
}