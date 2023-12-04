#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void){

    sigset_t block_set, prev_set;
    sigemptyset(&block_set); // block_set을 0으로 초기화
    sigaddset(&block_set, SIGINT); // block_set에 SIGINT 추가

    // 현재 block되고 있던 signal(없음)과 block_set에 있는 signal들(SIGNINT)을 UNION하여 block, prev_set에 block_set을 저장
    sigprocmask(SIG_BLOCK, &block_set, &prev_set); 
    printf("going to sleep for 5 seconds, try Ctrl + C\n");
    sleep(5);

    // pending signal들을 block_set에 저장
    sigpending(&block_set);
    // pending된 signal들 확인
    if(sigismember(&block_set, SIGINT)){
        printf("SIGINT is pending\n");
    }
    else{
        printf("SIGINT is not pending\n");
    }

    // prev_set에 있는 signal들만 block. 즉, 아무것도 block하지 않음.
    sigprocmask(SIG_SETMASK, &prev_set, NULL); 
    
    while(1){
        printf("Block Nothing...\n");
        sleep(1);
    }

    return 0;
}