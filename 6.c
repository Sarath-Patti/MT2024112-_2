/*
============================================================================
Name : 6.c
Author : Patti Sarath
Description : 6. Write a simple program to create three threads.

Date: 17 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Hello from thread %d\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];

    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
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

Hello from thread 2
Hello from thread 1
Hello from thread 3
*/
