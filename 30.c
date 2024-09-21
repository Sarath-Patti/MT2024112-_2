/*
============================================================================
Name : 30.c
Author : Patti Sarath
Description: 30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 20 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *data;
    char *readonly_data;

    key = ftok("/tmp", 'b');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        return 1;
    }

    strncpy(data, "This is some data written to shared memory", SHM_SIZE);

    if (shmdt(data) == -1) {
        perror("shmdt");
        return 1;
    }

    readonly_data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (readonly_data == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Read-only mode attached, data: %s\n", readonly_data);

    if (shmdt(readonly_data) == -1) {
        perror("shmdt");
        return 1;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}

/*

Read-only mode attached, data: This is some data written to shared memory
Shared memory removed successfully.

*/

