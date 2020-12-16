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

// Functions
pid_t *ask_for_children(int * des_children)
{
    printf("Give me the desired number of children:");
    scanf("%d", &des_children);  // wrong type passed since des children is pointer
    pid_t pid[des_children]; // wrong type passed since des children is pointer
    return pid; //  returns address instead of variable
}

// Main
int main()
{
    int des_children = 0; 
    pid_t *pid;
    pid = ask_for_children(&des_children);

    for(size_t i = 0; i < des_children; i++)
    {
        pid[i] = fork();
        printf(pid[i]);  // wrong type passed since pid is array 
    }


    printf("%d\n", des_children);
    return 0;
}