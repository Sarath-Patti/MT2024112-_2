/*
============================================================================
Name : 8a.c
Author : Patti Sarath
Description : 8. Write a program using signal system call to catch the following signals.
              a. SIGSEGV

Date: 18 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    int *p = NULL;
    *p = 10;  // Deliberate segmentation fault

    return 0;
}

/*
Caught SIGSEGV: Segmentation Fault

*/
