/*
============================================================================
Name : 12.c
Author : Patti Sarath
Description: 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process. 


Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        sleep(1);
        printf("Child Process: Sending SIGKILL to parent process (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL);
        printf("Child Process: This message might not be printed if parent is killed.\n");
        while (1) {
            sleep(1);
        }
    } else {
        printf("Parent Process: PID = %d\n", getpid());
        sleep(10);
        printf("Parent Process: Exiting...\n");
    }

    return 0;
}

/*

Parent Process: PID = 6185
Child Process: Sending SIGKILL to parent process (PID: 6185)
Child Process: This message might not be printed if parent is killed.
Killed

*/
