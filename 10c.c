/*
============================================================================
Name : 10c.c
Author : Patti Sarath
Description: 10. Write a  program using sigaction system call to catch the following signal
             c. SIGFPE

Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfpe_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGFPE: Floating-Point Exception\n");
    exit(1);
}

int main() {
    struct sigaction action;
    action.sa_sigaction = sigfpe_handler;
    action.sa_flags = SA_SIGINFO;

    sigaction(SIGFPE, &action, NULL);

    int zero = 0;
    int x = 5 / zero;  

    return 0;
}

/*

Caught SIGFPE: Floating-Point Exception

*/
