/*
============================================================================
Name : 5.c
Author : Patti Sarath
Description : 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.

Date: 17 sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to exec: %ld\n", arg_max);

    long max_procs = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user: %ld\n", max_procs);

    long clock_ticks = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second: %ld\n", clock_ticks);

    long open_files_max = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", open_files_max);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    struct sysinfo info;
    sysinfo(&info);
    long total_pages = info.totalram / page_size;
    printf("Total number of pages in physical memory: %ld\n", total_pages);

    long available_pages = info.freeram / page_size;
    printf("Number of currently available pages in physical memory: %ld\n", available_pages);

    return 0;
}
/*

Maximum length of arguments to exec: 2097152
Maximum number of simultaneous processes per user: 30125
Number of clock ticks per second: 100
Maximum number of open files: 1024
Size of a page: 4096 bytes
Total number of pages in physical memory: 1946762
Number of currently available pages in physical memory: 973053

*/
