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
        while(1)
        {
            sleep(1);
            printf("father id:%d ppid:%d\n", getpid(),getppid());
            if(0 != waitpid(0,NULL,WNOHANG))
            {
                break;
            }
        }
    }
    return 0;
}
