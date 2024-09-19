/*
============================================================================
Name : 12.c
Author : Patti Sarath
Description: 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 19 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Enter PID of the first program: ");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process %d\n", pid);
    kill(pid, SIGSTOP);

    return 0;
}

/*

Enter PID of the first program: 4140
Sending SIGSTOP signal to process 4140

*/
