#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 20
#define NUM 1000000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long sum = 0;

struct data{
    long long start;
    long long end;
    long long sum;
};

void* worker(void* arg){
    struct data* _mydata = (struct data*)arg;
    long long local_sum = 0;
    for (long long i = _mydata->start; i <= _mydata->end; i++){
        local_sum += i;
    }
    pthread_mutex_lock(&mutex);
    sum += local_sum;
    pthread_mutex_unlock(&mutex);
}
int main(void){

    struct data mydata[NUM_THREADS];
    pthread_t mythread[NUM_THREADS];

    printf("%d개의 thread를 생성하여, 1부터 %d까지의 합을 구한다.\n", NUM_THREADS, NUM);
    for (int i = 0; i < NUM_THREADS; i++) {
        mydata[i].start = ((NUM / NUM_THREADS) * i) + 1;
        mydata[i].end = (NUM / NUM_THREADS) * (i + 1);
        mydata[i].sum = 0;
        pthread_create(&mythread[i], NULL, worker, &mydata[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(mythread[i], NULL);
    }
    
    printf("final sum : %lld\n", sum);

    return 0;
}