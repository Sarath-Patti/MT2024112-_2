/*
============================================================================
Name : 33b.c
Author : Patti Sarath
Description: 33. Write a program to communicate between two machines using socket.
Date: 21 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sock, message, strlen(message), 0);
    printf("Message sent from client\n");

    read(sock, buffer, 1024);
    printf("Server: %s\n", buffer);

    close(sock);

    return 0;
}

/*

Message sent from client
Server: Hello from server

*/
