#include <stdio.h>
#include <sys/types.h>  
#include <unistd.h>

int main()
{
    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();
    // ERRORS : These functions are always successful. -> error handling 할 필요 없음

    printf("pid = %d\n", pid);
    printf("ppid = %d\n", ppid);
    
    return 0;
}