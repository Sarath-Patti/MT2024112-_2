/*
============================================================================
Name : 24.c
Author : Patti Sarath
Description: 24. Write a program to create a message queue and print the key and message queue id.
 Date: 19 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("/tmp", 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }
    
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*

Message Queue Key: 1627717633
Message Queue ID: 0

*/
