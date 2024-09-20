/*
============================================================================
Name : 19d.c
Author : Patti Sarath
Description: 19. Create a FIFO file by
d. mknod system call
Date: 19 sept, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int result = mknod("myfifo", S_IFIFO | 0666, 0);
    if (result == 0) {
        printf("FIFO created successfully using mknod system call.\n");
    } else {
        perror("Error creating FIFO");
    }
    return 0;
}
/*

FIFO created successfully using mknod system call.

*/
