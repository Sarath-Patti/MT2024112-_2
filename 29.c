/*
============================================================================
Name : 29.c
Author : Patti Sarath
Description: 29. Write a program to remove the message queue. 
Date: 20 sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("/tmp", 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

/*

Message queue removed successfully.

*/
