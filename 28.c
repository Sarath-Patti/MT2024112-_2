/*
============================================================================
Name : 28.c
Author : Patti Sarath
Description: 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 20 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

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

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode);

    buf.msg_perm.mode = 0644;

    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl");
        return 1;
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("New permissions: %o\n", buf.msg_perm.mode);

    return 0;
}

/*

Current permissions: 666
New permissions: 644

*/

