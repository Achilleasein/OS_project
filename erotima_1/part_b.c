// Includes
// Standar includes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Threading includes
#include <pthread.h>
#include <sys/wait.h>
//////////////////////////

// Defines
// We define the memory barrier, giving instructions to the processor through the program
#define MEMBAR __sync_synchronize()
#define THREAD_COUNT 8

// Defining variables
// volatile resources are defined that way to avoid any changes from the compiler, 
// since it informs the compiler that any slight change may create bug
volatile int tickets[THREAD_COUNT]; 
volatile int choosing[THREAD_COUNT];
volatile int resource;

