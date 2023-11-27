#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

struct two_double{
    double a;
    double b;
}data;

void sigint_handler(int _signo){
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void){
    struct sigaction sa;
    static struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigint_handler;
    if(sigaction(SIGALRM, &sa, NULL) == -1){
        perror("sigaction error : ");
        exit(0);
    }

    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM); // block_set에 SIGALRM 추가

    data = zeros;
    alarm(1);

    // while(1){
    //     data = zeros;
    //     data = ones;
    // }
    while(1){
        sigprocmask(SIG_BLOCK, &block_set, NULL); // SIGALRM block
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL); // SIGALRM unblock
        sigprocmask(SIG_BLOCK, &block_set, NULL); // SIGALRM block
        data = ones;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL); // SIGALRM unblock
    }

    return 0;
}