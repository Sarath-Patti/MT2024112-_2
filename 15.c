/*
============================================================================
Name : 15.c
Author : Patti Sarath
Description: 15. Write a simple program to send some data from parent to the child process.
Date: 19 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefds[2];
    pid_t pid;
    char write_msg[] = "Data from parent to child";
    char read_msg[100];

    if (pipe(pipefds) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        close(pipefds[1]);
        read(pipefds[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(pipefds[0]);
    } else {
        close(pipefds[0]);
        write(pipefds[1], write_msg, strlen(write_msg) + 1);
        close(pipefds[1]);
    }

    return 0;
}

/*

Child received: Data from parent to child

*/
