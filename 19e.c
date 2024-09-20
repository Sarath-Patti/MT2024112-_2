/*
============================================================================
Name : 19e.c
Author : Patti Sarath
Description: 19. Create a FIFO file by
e. mkfifo library function
Date: 19 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int result = mkfifo("myfifo1", 0666);
    if (result == 0) {
        printf("FIFO created successfully using mkfifo library function.\n");
    } else {
        perror("Error creating FIFO");
    }
    return 0;
}

/*

FIFO created successfully using mkfifo library function.

*/
