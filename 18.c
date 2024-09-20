/*
============================================================================
Name : 18.c
Author : Patti Sarath
Description: 18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 19 sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2];
    
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("pipe failed");
        exit(1);
    }

    if (fork() == 0) {
        dup2(fd1[1], 1);
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls", "ls", "-Rl", (char*) NULL);
        perror("execlp ls failed");
        exit(1);
    }

    if (fork() == 0) {
        dup2(fd2[1], 1);
        dup2(fd1[0], 0);
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("grep", "grep", "^c", (char*) NULL);
        perror("execlp grep failed");
        exit(1);
    }

    close(fd1[0]);
    close(fd1[1]);
    dup2(fd2[0], 0);
    close(fd2[0]);
    close(fd2[1]);
    execlp("wc", "wc", (char*) NULL);
    perror("execlp wc failed");
    exit(1);
}
/*
       0       0       0
*/
