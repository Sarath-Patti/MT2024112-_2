/*
============================================================================
Name : 7.c
Author : Patti Sarath
Description : 7. Write a simple program to print the created thread ids. 

Date: 18 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    return 0;
}

/*
Thread ID: 139712132015808
Thread ID: 139712123623104
Thread ID: 139712140408512
*/
