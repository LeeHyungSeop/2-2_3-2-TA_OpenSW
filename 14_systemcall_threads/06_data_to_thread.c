/*
    structure에 시작값과 마지막값을 넣어서 thread에 전달하라.
    thread는 worker() 함수를 실행.
    worker() 함수는 시작값부터 마지막값까지의 합을 구하고, 
    결과를 structure의 sum에 저장.

    thread가 종료하면, main thread는 thread가 계산한 결과를 출력.
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 1

struct data{
    int start;
    int end;
    long long sum;
};

void *worker(void *arg) {
    struct data* _mydata = (struct data*)arg;
    long long local_sum = 0;
    for (int i = _mydata->start; i <= _mydata->end; i++){
        local_sum += i;
    }
    _mydata->sum = local_sum;
}

int main(void){
    pthread_t mythread[NUM_THREADS];
    struct data mydata[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++){
        mydata[i].start = 1;
        mydata[i].end = 100;
        mydata[i].sum = 0;
        pthread_create(&mythread[i], NULL, worker, &mydata[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(mythread[i], NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++){
        printf("mydata[%d].sum = %lld\n", i, mydata[i].sum);
    }
    
    return 0;
}