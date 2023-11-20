#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <stdio.h>
#define BUF_SIZE 1

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("usage : %s source-file dest-file\n", argv[0]);
        return 0;
    }

    int fd_src = open(argv[1], O_RDONLY);
    int fd_des = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0664);
    if (fd_src == -1 || fd_des == -1){ // file open error
        perror("open file fail");
        return 0;
    }
    else{
        int nb;
        char buf[BUF_SIZE];
        while(1){
        nb = read(fd_src, buf, BUF_SIZE);
        if(nb == 0){
            break;
        }
        write(fd_des, buf, nb); // nb(읽어온만큼)만큼 write해야 함
        }
    }
    return 0;
}