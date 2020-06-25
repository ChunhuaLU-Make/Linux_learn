#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        /* child process*/
        printf("child id:%d ppid:%d\n", getpid(), getppid());
        sleep(10);
    }
    else
    {
        /* father process */
        int i = 0;
        while(1)
        {
            if(i == 3)
            {
                break;
            }
            sleep(1);
            printf("father id:%d ppid:%d\n", getpid(),getppid());
            i++;
        }
        printf("call wait return value:%d\n",wait(NULL));
    }
    return 0;
}
