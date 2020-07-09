#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    pid_t pid = fork();
    if(pid > 0)
    {
        while(1)
        {
            printf("MY name father\n");
            sleep(1);
        }
    }

    if(pid == 0)
    {
        sleep(5);
        kill(getppid(), SIGKILL);
    }
    return 0;
}
