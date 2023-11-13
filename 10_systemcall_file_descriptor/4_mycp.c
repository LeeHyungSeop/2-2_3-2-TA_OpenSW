/*
    cp 명령어와 유사한 program을 작성하자
    mycp는 첫번째 인자로 지정된 파일을 두번째 인자로 지정한 파일로 복사한다
    mycp [source] [destination]
    destination의 mode는 rw-r--r--로 설정한다
*/

#include <stdio.h>
#include <sys/types.h>  // open()
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h> // close()

#define BUF_SIZE 128

int main(int argc, char* argv[]) {

    if(argc != 3){
        printf("usage : ./mycp [source] [destination]\n");
        exit(0);
    }

    int copy_fd = open(argv[1], O_RDONLY);
    int paste_fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(copy_fd == -1) {
        printf("open error : %d\n", errno);
        perror("error msg is : ");
        exit(0);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_bytes;
    // copy and paste
    while(1){
        read_bytes = read(copy_fd, readStr, BUF_SIZE);
        if(read_bytes == -1){
            perror("read error : ");
            exit(0);
        }
        if(read_bytes == 0){ // EOF
            break;
        }
        write(paste_fd, readStr, read_bytes);
    }

    // [destination] file에 paste된 내용을 read
    lseek(paste_fd, 0, SEEK_SET);
    while(1) {
        read_bytes = read(paste_fd, readStr, BUF_SIZE);
        if(read_bytes == -1){
            perror("read error : ");
            exit(0);
        }
        if(read_bytes == 0){ // EOF
            break;
        }
        printf("%s\n", readStr);
    }

    free(readStr);
    close(paste_fd);
    close(copy_fd);

    return 0;
}