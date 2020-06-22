#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int i = 0;
    pid_t pid;
    for(i = 0; i < 3; i++)
    {
        pid = fork();
        if(pid == 0)
        {
            break;
        }
        /* for loop end ++ */
    }
    
    /* Create lost of brother  process */
    if(i == 0)
    {
        printf("child:%d father:%d\n", getpid(),getppid());
    }

    if(i == 1)
    {
        printf("1 child:%d father:%d\n", getpid(),getppid());
    }

    if(i == 2)
    {
        printf("2 child:%d father:%d\n", getpid(),getppid());
    }

    if(i == 3)
    {
        /* This is a father process */
        printf("3 child:%d father:%d\n", getpid(),getppid());
    }
    usleep(10);
    return 0;
}
