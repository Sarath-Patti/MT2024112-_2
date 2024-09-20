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
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100

struct message_buffer {
    long msg_type;
    char msg_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct message_buffer message;

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

    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) == -1) {
        perror("msgrcv");
        return 1;
    }

    printf("Received message: %s\n", message.msg_text);

    return 0;
}

/*

msgrcv: No message of desired type

*/
