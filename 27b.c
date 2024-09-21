/*
============================================================================
Name : 27b.c
Author : Patti Sarath
Description: 27. Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
Date: 20 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgrcv(msgid, &message, sizeof(message.msg_text), 0, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message available.\n");
        } else {
            perror("msgrcv");
        }
    } else {
        printf("Received message: %s\n", message.msg_text);
    }

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
/*
No message available.
*/
