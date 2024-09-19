/*
============================================================================
Name : 8f.c
Author : Patti Sarath
Description : 8. Write a program using signal system call to catch the following signals.
              f. SIGVTALRM (use setitimer system call)


Date: 18 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>  

void sigvtalrm_handler(int signum) {
    printf("Caught SIGVTALRM: Virtual Timer Alarm Signal\n");
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, sigvtalrm_handler);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    pause();  

    return 0;
}

