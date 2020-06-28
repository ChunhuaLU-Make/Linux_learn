#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    /* pipe fd[0]:read fd[1]:write*/
    int pipefd[2];

    if(pipe(pipefd))
    {
        perror("pipe");
        exit(1);
    }

    /* Replace the file descriptor */

    pid_t pid = fork();
    if(pid == 0)
    {
        close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
        execlp("ps", "ps", "-aux", NULL);
        perror("execlp");
        exit(1);
    }
    if(pid > 0)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        execlp("grep","grep", "bash",NULL);
        perror("execlp");
        exit(1);
    }

}
