#include <unistd.h>
#include <stdio.h>

int main()
{
    for(int i = 0; i < 10; i++)
    {
        printf("i == :%d\n", i);
    }

    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child:%d father:%d\n",getpid(), getppid());
        /* child process .txt replace ./hell */
        execl("./hell", "a.out", NULL);
    }

    for(int i = 0; i < 3; i++)
    {
        /* child process not execute */
        printf("father working:%d\n", getpid());
    }
    usleep(1000);
    return 0;
}
