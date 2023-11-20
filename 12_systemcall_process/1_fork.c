/*
    fork()의 리턴값을 확인하여 자식과 부모 프로세스를 구분하도록 
    자신의 pid와 ppid를 출력하자
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {

    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("child pid  : %d, ppid : %d\n", getpid(), getppid());
    } else {
        printf("parent pid : %d, ppid : %d\n", getpid(), getppid());
    }

    return 0;
}