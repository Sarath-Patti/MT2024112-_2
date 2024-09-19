/*
============================================================================
Name : 13.c
Author : Patti Sarath
Description: 13.Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 19 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum) {
    printf("Caught signal: %d\n", signum);
}

int main() {
    struct sigaction action;
    action.sa_handler = sig_handler;
    sigaction(SIGSTOP, &action, NULL);

    printf("First Program PID: %d\n", getpid());
    printf("Waiting for SIGSTOP signal...\n");

    while (1) {
        pause();
    }

    return 0;
}

/*

First Program PID: 4140
Waiting for SIGSTOP signal...
*/
