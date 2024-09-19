/*
============================================================================
Name : 11.c
Author : Patti Sarath
Description:  11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.


Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum, siginfo_t *info, void *context) {
}

int main() {
    struct sigaction action;

    action.sa_handler = SIG_IGN;
    action.sa_flags = 0;
    sigemptyset(&action.sa_mask);
    sigaction(SIGINT, &action, NULL);
    printf("SIGINT is now ignored. Press Ctrl+C...\n");
    sleep(5);

    action.sa_handler = SIG_DFL;
    sigaction(SIGINT, &action, NULL);
    printf("SIGINT default action restored. Press Ctrl+C again to exit.\n");

    while (1) {
        pause();
    }

    return 0;
}

/*

SIGINT is now ignored. Press Ctrl+C...
SIGINT default action restored. Press Ctrl+C again to exit.

*/
