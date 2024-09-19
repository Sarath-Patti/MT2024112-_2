/*
============================================================================
Name : 8g.c
Author : Patti Sarath
Description : 8. Write a program using signal system call to catch the following signals.
            g. SIGPROF (use setitimer system call) 


Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>  // Include unistd.h for pause()

void sigprof_handler(int signum) {
    printf("Caught SIGPROF: Profiling Timer Alarm Signal\n");
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, sigprof_handler);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    pause();  // Wait for signal

    return 0;
}

