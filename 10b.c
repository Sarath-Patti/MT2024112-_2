/*
============================================================================
Name : 10b.c
Author : Patti Sarath
Description :10. Write a  program using sigaction system call to catch the following signals. 
             b. SIGINT


Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>  

void sigint_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGINT: Interrupt from Keyboard\n");
    exit(1);
}

int main() {
    struct sigaction action;
    action.sa_sigaction = sigint_handler;
    action.sa_flags = SA_SIGINFO;

    sigaction(SIGINT, &action, NULL);

    while (1) {
        printf("Press Ctrl+C to trigger SIGINT...\n");
        sleep(1);  
    }

    return 0;
}

/*

Press Ctrl+C to trigger SIGINT...
Press Ctrl+C to trigger SIGINT...
Press Ctrl+C to trigger SIGINT...
Press Ctrl+C to trigger SIGINT...

*/
