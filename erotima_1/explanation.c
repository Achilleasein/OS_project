#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#define N 2

int main()
{
    pid_t pid[N];
    int child_status;

    for (size_t i = 0; i < N; i++) // does N iterations
    {
        pid[i] = fork(); // forks the process and stores it in an array
        if (pid[i] == 0)
        {
            sleep(2-2*i); // sleeps for specific time
            exit(1+i); // exit spcified child
        }
    }
    
    for (size_t i = 0; i < N; i++)// again N iterations
    {
        pid_t wpid = waitpid(pid[i], &child_status, 0); // waits for the specific child to finish

        if (WIFEXITED(child_status)) // check if the child finished properly
        {
            printf("Child %d terminated with exit status %d\n" , wpid, WEXITSTATUS(child_status));
        }
        else
        {
            printf("Child %d termianted abnormally\n", wpid);
        }
        
    }
    
    return(0);
}


