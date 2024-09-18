/*
============================================================================
Name : 3.c
Author : Patti Sarath
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.

Date: 17 sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void set_new_limit() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Current limits for number of open files:\n");
        printf("  Soft limit: %llu\n", (unsigned long long)limit.rlim_cur);
        printf("  Hard limit: %llu\n", (unsigned long long)limit.rlim_max);
    } else {
        perror("Error getting current limit");
        exit(EXIT_FAILURE);
    }

    limit.rlim_cur = 1024;

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Successfully set new soft limit to 1024\n");
    } else {
        perror("Error setting new limit");
        exit(EXIT_FAILURE);
    }

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New limits for number of open files:\n");
        printf("  Soft limit: %llu\n", (unsigned long long)limit.rlim_cur);
        printf("  Hard limit: %llu\n", (unsigned long long)limit.rlim_max);
    } else {
        perror("Error getting new limit");
        exit(EXIT_FAILURE);
    }
}

int main() {
    set_new_limit();
    return 0;
}
/*

Current limits for number of open files:
  Soft limit: 1024
  Hard limit: 1048576
Successfully set new soft limit to 1024
New limits for number of open files:
  Soft limit: 1024
  Hard limit: 1048576

*/
