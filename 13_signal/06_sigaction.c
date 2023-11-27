// SIGINT(ctrl + C), SIGQUIT(ctrl + \)에 대한 signal handler를 등록하기
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sigint_handler(int _signo){
    printf("This is SIGINT handler\n");
    printf("Signal number is %d\n", _signo);
}
void sigquit_handler(int _signo){
    printf("This is SIGQUIT handler\n");
    printf("Signal number is %d\n", _signo);
}

int main(void){

    struct sigaction sa_sigint;
    struct sigaction sa_sigquit;

    sa_sigint.sa_handler = sigint_handler; // SIGINT가 들어오면, sigint_handler를 실행
    sigemptyset(&(sa_sigint.sa_mask)); // sa_mask를 0으로 초기화 -> signal handler가 실행되는 동안에는 다른 signal blocking
    if(sigaction(SIGINT, &sa_sigint, NULL) == -1){
        perror("SIGINT sigaction error : ");
        exit(0);
    }

    sa_sigint.sa_flags = 0;
    sa_sigquit.sa_handler = sigquit_handler; // SIGQUIT가 들어오면, sigquit_handler를 실행
    sigemptyset(&(sa_sigquit.sa_mask)); // sa_mask를 0으로 초기화 -> signal handler가 실행되는 동안에는 다른 signal blocking
    sa_sigquit.sa_flags = 0;
    if(sigaction(SIGQUIT, &sa_sigquit, NULL) == -1){
        perror("SIGQUIT sigaction error : ");
        exit(0);
    }
    
    while(1){
        printf("pid = %d\n", getpid());
        sleep(1);
    }

    return 0;
}