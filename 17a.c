/*
============================================================================
Name : 17a.c
Author : Patti Sarath
Description: 17. Write a program to execute ls -l | wc.
a. use dup
Date: 19 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
int fd[2];
pipe(fd);
if (!fork()) {
close(1); 
close(fd[0]);
dup(fd[1]); 
execlp("ls", "ls", "-l", (char*) NULL);
}
else {
close(0); 
close(fd[1]);
dup(fd[0]); 
execlp("wc", "wc", (char*) NULL);
}
}

/*

61     542    3734

*/
