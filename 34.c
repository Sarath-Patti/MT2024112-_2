/*
============================================================================
Name : 34a.c
Author : Patti Sarath
Description: 34. Write a program to create a concurrent server.
a. use fork
Date: 21 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PORT 8080
#define BACKLOG 5

void handle_client(int new_socket) {
    char buffer[1024] = {0};
    char *message = "Hello from server";
    
    read(new_socket, buffer, 1024);
    printf("Client: %s\n", buffer);
    send(new_socket, message, strlen(message), 0);
    printf("Message sent from server\n");
    close(new_socket);
    exit(0);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, BACKLOG);
    
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        
        if (fork() == 0) { 
            close(server_fd);
            handle_client(new_socket);
        } else {
            close(new_socket);
        }
    }
    
    return 0;
}

/*


Client: sarath

Message sent from server


*/
