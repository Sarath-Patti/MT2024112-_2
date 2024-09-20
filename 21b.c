/*
============================================================================
Name : 21.c
Author : Patti Sarath
Description: 21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 19 sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path_write = "myfifo_write";
    const char *fifo_path_read = "myfifo_read";
    char buffer[100];
    int fd_write, fd_read;

    mkfifo(fifo_path_write, 0666);
    mkfifo(fifo_path_read, 0666);

    fd_read = open(fifo_path_write, O_RDONLY);
    fd_write = open(fifo_path_read, O_WRONLY);

    read(fd_read, buffer, sizeof(buffer) - 1);
    printf("Reader received: %s\n", buffer);

    write(fd_write, "Hello from reader!", 19);

    close(fd_write);
    close(fd_read);

    return 0;
}

/*
Reader  received: Hello from writer!
*/
