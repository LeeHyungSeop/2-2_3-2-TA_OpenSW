#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*
    Infinite Loop 안에서 pid 출력
    SIGINT = Ctrl + C
*/

int main(void){
    pid_t pid;
    while(1){
        pid = getpid();
        printf("pid: %d\n", pid);
        sleep(1);
    }
    return 0;
}  