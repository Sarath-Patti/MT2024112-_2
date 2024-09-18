/*
============================================================================
Name : 4.c
Author : Patti Sarath
Desription: 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

Date: 17 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();

    printf("CPU cycles taken for 100 getppid() calls: %llu\n", end - start);

    return 0;
}

/*

CPU cycles taken for 100 getppid() calls: 72491

*/
