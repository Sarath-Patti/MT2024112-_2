/*
============================================================================
Name : 20b.c
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
    char buffer[100];

    int fd = open(fifo_path, O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Received: %s\n", buffer);

    close(fd);

    return 0;
}

/*

Received: Hello from writer!

*/
