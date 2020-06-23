#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int temp = 100;

int main()
{
    int i = 0;
    pid_t pid;
    for(i = 0; i < 2; i++)
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
        printf("child:%d temp%d\n", getpid(), temp);
    }

    if(i == 1)
    {
        printf("child 1:%d temp:%d\n", getpid(), ++temp);
    }

    if(i == 2)
    {
        /* This is a father process */
        printf("3 child:%d father:%d\n", getpid(),getppid());
    }
    usleep(10);
    return 0;
}
