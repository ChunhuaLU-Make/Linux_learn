#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid > 0)
    {
        int pid_status;
        while(1)
        {
            if(0 != waitpid(0, &pid_status, WNOHANG))
            {
                if(WIFSIGNALED(pid_status))
                {
                    printf("kill sig:%d\n",WTERMSIG(pid_status));
                }
                break;
            }
            printf("child wait kill\n");
            sleep(1);
        }
    }
    if(pid == 0)
    {
        sleep(10);
        raise(SIGKILL);
    }
    return 0;
}
