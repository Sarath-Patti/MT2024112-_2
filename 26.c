/*
============================================================================
Name : 26.c
Author : Patti Sarath
Description: 26. Write a program to send messages to the message queue. Check $ipcs -q
Date: 20 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

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

    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    message.msg_type = 1;
    printf("Enter a message: ");
    fgets(message.msg_text, MAX, stdin);

    if (msgsnd(msgid, &message, strlen(message.msg_text) + 1, 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent to the queue: %s", message.msg_text);

    return 0;
}

/*

Enter a message: Hii
Message sent to the queue: Hii

*/
