/*
============================================================================
Name : 23.c
Author : Patti Sarath
Description: 23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 19 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int main() {
    struct rlimit rlim;
    int pipefd[2];

    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Maximum number of files that can be opened: %ld\n", rlim.rlim_cur);
    } else {
        perror("getrlimit");
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    printf("Size of the pipe buffer: %d bytes\n", PIPE_BUF);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

/*

Maximum number of files that can be opened: 1024
Size of the pipe buffer: 4096 bytes

*/
