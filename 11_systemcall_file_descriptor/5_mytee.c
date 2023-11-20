/*
    stdin으로 받아들인 input을
    stdout과 지정한 file들로 output.

    usage : ./mytee [file1] [file2] ...
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]){

    if(argc < 2) {
        printf("usage : ./mytee [file1] [file2] ... ([file1]지정은 필수)\n");
        exit(0);
    }
    // 받은 file 개수만큼 descriptor 생성
    char* paste_fd = (char*)malloc(sizeof(char) * argc);

    for (char i = 1; i < argc; i++)
    {
        paste_fd[i] = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if(paste_fd[i] == -1) {
            printf("open error : %d\n", errno);
            perror("error msg is : ");
            exit(0);
        }
    }

    // stdin을 read할 buffer
    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int stdin_bytes;
    // stdin으로부터 read, stdout과 file들에 write
    while(1){
        stdin_bytes = read(0, readStr, BUF_SIZE); // 0 = STDIN_FIELNO
        if(stdin_bytes == 0){ // EOF
            break;
        }
        write(1, readStr, BUF_SIZE); // 1 = STDOUT_FILENO
        for (char i = 1; i < argc; i++)
        {
            write(paste_fd[i], readStr, BUF_SIZE);
        }
    }
    
    // 열었던 file 모두 close
    for (char i = 0; i < argc; i++)
    {
        close(paste_fd[i]);
    }

    free(paste_fd);
    free(readStr); 

    return 0;
}