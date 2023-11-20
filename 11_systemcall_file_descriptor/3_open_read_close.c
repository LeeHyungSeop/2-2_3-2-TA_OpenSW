#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]){

    if (argc != 2){
        printf("usage : ./3_open_read_close [filename]\n");
        exit(0);
    }

    int open_fd = open(argv[1], O_RDONLY);
    if (open_fd == -1) {
        printf("open error : %d\n", errno);
        perror("error msg is : ");
        exit(0);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_fd;
    while(1){
        read_fd = read(open_fd, readStr, BUF_SIZE);
        if(read_fd == -1) {
            printf("read error : %d\n", errno);
            perror("error msg is : ");
            exit(0);
        }
        else if(read_fd == 0) {
            printf("----- End Of File -----\n");
            close(open_fd);
            break;
        }
        else {
            printf("%s\n", readStr);
        }
    }

    free(readStr);
    close(read_fd);
    close(open_fd);

    return 0;
}