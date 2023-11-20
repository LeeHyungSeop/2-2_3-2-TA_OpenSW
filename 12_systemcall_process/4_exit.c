#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> // wait()
#include <stdlib.h> // exit()

int main(void) {

    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("child pid  : %d, ppid : %d\n", getpid(), getppid());
        exit(101); // 종료하면서 parent한테 101이라는 status code를 넘긴다
    } 
    else {
        int exitstatus;
        wait(&exitstatus);
        printf("parent pid : %d, ppid : %d\n", getpid(), getppid());
        /*  
            그냥 이렇게만 출력하면 101이 출력이 안된다.
            bit mask를 통해 exit status를 추출해야 한다. 
                --> WEXITSTATUS() 매크로 사용
        */
        printf("child procecss의 exit code : %d\n", exitstatus); 
        printf("방법 1 : child procecss의 exit code 추출 : %d\n", exitstatus >> 8); 
        printf("방법 2 : child procecss의 exit code 추출 : %d\n", WEXITSTATUS(exitstatus)); 
    }

    return 0;
}