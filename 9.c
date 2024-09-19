/*
============================================================================
Name : 9.c
Author : Patti Sarath
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.


Date: 18 sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("Caught SIGINT, but it is being ignored!\n");
}

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now ignored. Press Ctrl+C...\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("SIGINT default action restored. Press Ctrl+C again to exit.\n");

    while (1) {
        pause();
    }

    return 0;
}

/*

SIGINT is now ignored. Press Ctrl+C...\

*/
