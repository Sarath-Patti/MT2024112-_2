/*
============================================================================
Name : 1c.c
Author : Patti Sarath
Description : 1.Write a  program  to set a interval timer in 10sec and
              10micro second
              c.ITIMER_PROF
Date: 17 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_profalarm(int signum) {
    printf("ITIMER_PROF expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handle_profalarm);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error setting timer");
        return 1;
    }

    while(1) {
        for (volatile int i = 0; i < 100000000; i++);
    }

    return 0;
}

/*

ITIMER_PROF expired!
ITIMER_PROF expired!

*/
