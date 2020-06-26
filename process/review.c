#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    uint8_t total = 3;
    uint8_t i = 0;
    for(i = 0; i < total; i++)
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            break;
        }
    }

    if(i == 0)
    {
        printf("i = 0, pid:%d\n", getpid());
        execlp("ls","ls", NULL);
        perror("execlp ls");
        exit(1);
    }
    else if(i == 1)
    {
        printf("i = 1, pid:%d\n", getpid());
        execl("./hell", "hell", NULL);
    }
    else if(i == 2)
    {
        printf("i = 2, pid:%d\n", getpid());
        printf("My name is Linux\n");
        exit(2);
    }
    else
    {
        int status;
        pid_t pid;
        while(1)
        {
            pid = wait(&status);
            if(pid == -1)
            {
                break;
            }

            if(WIFEXITED(status))
            {
                printf("id:%d kill status %d\n", pid, WEXITSTATUS(status));
            }
            
            if(WIFSIGNALED(status))
            {
                printf("id:%d kill signal:%d\n",pid, WTERMSIG(status));
            }
        }
    }
    return 0;
}
