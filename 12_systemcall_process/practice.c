#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int my_system(const char* command){

    pid_t pid = fork();
    int status;

    if(pid < 0){
        status = -1;
    }
    if(pid == 0){
        if(command == NULL) {
            status = 0;
        }
        execl("/bin/sh", "sh", "-c", command, (char*)NULL);
    }
    else {
        int exitStatus;
        wait(&exitStatus);
    }

}

int main(void) {

    int ret = my_system("ls -l | wc -l");
    printf("exit code %d\n", ret);



}