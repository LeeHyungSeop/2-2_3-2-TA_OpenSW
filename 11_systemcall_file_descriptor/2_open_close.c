#include <stdio.h>
#include <sys/types.h>  // open()
#include <sys/stat.h>   
#include <fcntl.h> 
#include <unistd.h> // close()
#include <stdlib.h> // exit()
#include <errno.h> // errno, perror()

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("usage : ./2_open_close [filename]\n");
        exit(0);
    }

    int open_fd = open(argv[1], O_RDONLY); // open with read only mode
    if(open_fd == -1) {
        printf("open error : %d\n", errno);
        perror("error msg is ");
        exit(0);
    }
    else {
        printf("open success\n");
        close(open_fd);
    }

    return 0;
}