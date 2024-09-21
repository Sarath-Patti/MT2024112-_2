/*
============================================================================
Name : 31.c
Author : Patti Sarath
Description: 31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 21 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("/tmp", 'B');
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    if (semid == -1) {
        perror("semget");
        return 1;
    }

    semctl(semid, 0, SETVAL, 1);

    printf("Binary semaphore created and initialized to 1.\n");

    return 0;
}

/*

Binary semaphore created and initialized to 1.

*/
