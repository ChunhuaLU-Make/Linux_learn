#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    /* The create a progress */
    pid = fork();
    if(pid < 0)
    {
        /* create fail output error information */
        perror("error");
        exit(1);
    }

    if(pid == 0)
    {
        /* if is child progress, execute*/
        for(int i = 0; i < 10; i++)
        {
            /* print output child progress id and father progress id */
            printf("child id:%d => father: %d\n",getpid(),getppid());

        } 
    }
    else
    {
        /* Father progress execute */
        for(int i = 0; i < 10; i++)
        {
            /* delay 1us use child progress execute */
            usleep(1);

            /* Print output child id, father id, grandpa id */
            printf("child:%d father id:%d ==> grandpa:%d\n",pid, getpid(), getppid());
        }
    }
    return 0;
}
