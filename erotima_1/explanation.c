#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#define N 30

int main()
{
    pid_t pid[N];
    int child_status;

    for (size_t i = 0; i < N; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            sleep(60-2*i);
            exit(100+i);
        }
    }
    
    for (size_t i = 0; i < N; i++)
    {
        pid_t wpid = waitpid(pid[i], &child_status, 0);

        if (WIFEXITED(child_status))
        {
            printf("Child%d terminated with exit status %d\n" , wpid, WEXITSTATUS(child_status));
        }
        else
        {
            printf("Child%d termianted abnormally\n", wpid);
        }
        
    }
    
    return(0);
}
