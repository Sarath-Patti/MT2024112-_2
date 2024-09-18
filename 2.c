/*
============================================================================
Name : 2.c
Author : Patti Sarath
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.

Date: 17 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *resource_name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%s Limits:\n", resource_name);

        if (limit.rlim_cur == RLIM_INFINITY) {
            printf("  Current limit: Unlimited\n");
        } else {
            printf("  Current limit: %llu\n", (unsigned long long)limit.rlim_cur);
        }

        if (limit.rlim_max == RLIM_INFINITY) {
            printf("  Maximum limit: Unlimited\n");
        } else {
            printf("  Maximum limit: %llu\n", (unsigned long long)limit.rlim_max);
        }
    } else {
        perror("Error getting resource limit");
        exit(EXIT_FAILURE);
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU Time");
    print_limit(RLIMIT_FSIZE, "File Size");
    print_limit(RLIMIT_DATA, "Data Segment Size");
    print_limit(RLIMIT_STACK, "Stack Size");
    print_limit(RLIMIT_CORE, "Core File Size");
    print_limit(RLIMIT_RSS, "Resident Set Size");
    print_limit(RLIMIT_NOFILE, "Number of Open Files");
    print_limit(RLIMIT_AS, "Address Space Size");
    print_limit(RLIMIT_NPROC, "Number of Processes");
    print_limit(RLIMIT_MEMLOCK, "Locked Memory");
    print_limit(RLIMIT_LOCKS, "File Locks");

    return 0;
}

/*

CPU Time Limits:
  Current limit: Unlimited
  Maximum limit: Unlimited
File Size Limits:
  Current limit: Unlimited
  Maximum limit: Unlimited
Data Segment Size Limits:
  Current limit: Unlimited
  Maximum limit: Unlimited
Stack Size Limits:
  Current limit: 8388608
  Maximum limit: Unlimited
Core File Size Limits:
  Current limit: 0
  Maximum limit: Unlimited
Resident Set Size Limits:
  Current limit: Unlimited
  Maximum limit: Unlimited
Number of Open Files Limits:
  Current limit: 1024
  Maximum limit: 1048576
Address Space Size Limits:
  Current limit: Unlimited
  Maximum limit: Unlimited
Number of Processes Limits:
  Current limit: 30125
  Maximum limit: 30125
Locked Memory Limits:
  Current limit: 996741120
  Maximum limit: 996741120
File Locks Limits:
  Current limit: Unlimited
  Maximum limit: Unlimited

*/
