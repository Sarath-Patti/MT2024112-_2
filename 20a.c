/*
============================================================================
Name : 20a.c
Author : Patti Sarath
Description: 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 19 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path = "myfifo";
    char message[] = "Hello from writer!";
    
    mkfifo(fifo_path, 0666);

    int fd = open(fifo_path, O_WRONLY);

    write(fd, message, sizeof(message));

    close(fd);

    return 0;
}
