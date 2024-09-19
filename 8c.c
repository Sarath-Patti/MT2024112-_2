/*
============================================================================
Name : 8c.c
Author : Patti Sarath
Description : 8. Write a program using signal system call to catch the following signals.
              c. SIGFPE


Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE: Floating-Point Exception\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);

    int zero = 0;
    int x = 5 / zero;  

    return 0;
}


/*
Caught SIGFPE: Floating-Point Exception
*/
