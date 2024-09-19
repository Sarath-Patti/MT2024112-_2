/*
============================================================================
Name : 16.c
Author : Patti Sarath
Description: 16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 19 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    char parent_msg[] = "Message from parent to child";
    char child_msg[] = "Message from child to parent";
    char read_msg[100];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        close(pipe1[1]);
        close(pipe2[0]);

        read(pipe1[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);

        write(pipe2[1], child_msg, strlen(child_msg) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        close(pipe1[0]);
        close(pipe2[1]);

        write(pipe1[1], parent_msg, strlen(parent_msg) + 1);

        read(pipe2[0], read_msg, sizeof(read_msg));
        printf("Parent received: %s\n", read_msg);

        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}
/*

Child received: Message from parent to child
Parent received: Message from child to parent

*/
