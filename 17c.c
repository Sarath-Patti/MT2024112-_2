/*
============================================================================
Name : 17c.c
Author : Patti Sarath
Description: 17. Write a program to execute ls -l | wc.
c. use fcntl
Date: 19 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
int fd[2];
pipe(fd);
if (!fork()) {
close(1); 
close(fd[0]);
fcntl(fd[1], F_DUPFD, STDOUT_FILENO); 
execlp("ls", "ls", "-l", (char*) NULL);
}
else {
close(0); 
close(fd[1]);
fcntl(fd[0], F_DUPFD, STDIN_FILENO); 
execlp("wc", "wc", (char*) NULL);
}
}

/*
     65     578    3986
*/
