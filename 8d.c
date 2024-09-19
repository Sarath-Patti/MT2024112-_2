/*
============================================================================
Name : 8d.c
Author : Patti Sarath
Description : 8. Write a program using signal system call to catch the following signals.
              d. SIGALRM (use alarm system call)


Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM: Alarm Signal\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler);

    alarm(2);  // Set alarm for 2 seconds

    pause();  // Wait for signal

    return 0;
}

/*
Caught SIGALRM: Alarm Signal
*/
