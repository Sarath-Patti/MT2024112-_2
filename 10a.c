/*
============================================================================
Name : 10a.c
Author : Patti Sarath
Description: 10. Write a  program using sigaction system call to catch the following signals.
a. SIGSEGV 


Date: 18 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1);
}

int main() {
    struct sigaction action;
    action.sa_sigaction = sigsegv_handler;
    action.sa_flags = SA_SIGINFO;

    sigaction(SIGSEGV, &action, NULL);

    int *p = NULL;
    *p = 10;  

    return 0;
}

/*

Caught SIGSEGV: Segmentation Fault

*/
