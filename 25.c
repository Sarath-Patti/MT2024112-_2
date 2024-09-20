/*
============================================================================
Name : 25.c
Author : Patti Sarath
Description: 25.Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 20 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

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

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Access permissions: %o\n", buf.msg_perm.mode);
    printf("UID: %u, GID: %u\n", buf.msg_perm.uid, buf.msg_perm.gid);
    printf("Time of last message sent: %s", ctime(&buf.msg_stime));
    printf("Time of last message received: %s", ctime(&buf.msg_rtime));
    printf("Time of last change: %s", ctime(&buf.msg_ctime));
    printf("Size of the queue: %lu bytes\n", buf.__msg_cbytes);
    printf("Number of messages in the queue: %lu\n", buf.msg_qnum);
    printf("Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*

Access permissions: 666
UID: 1000, GID: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change: Fri Sep 20 11:00:14 2024
Size of the queue: 0 bytes
Number of messages in the queue: 0
Maximum number of bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0

*/
