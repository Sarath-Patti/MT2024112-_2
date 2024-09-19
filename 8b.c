
/*
============================================================================
Name : 8b.c
Author : Patti Sarath
Description : 8. Write a program using signal system call to catch the following signals.
             b. SIGINT


Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>  

void sigint_handler(int signum) {
    printf("Caught SIGINT: Interrupt from Keyboard\n");
    exit(1);
}

int main() {
    signal(SIGINT, sigint_handler);

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
