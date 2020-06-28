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
    dup2(pipefd[1], STDOUT_FILENO); //ps -aux
    dup2(pipefd[0], STDIN_FILENO);  //grep "bash"
    char ch;

    write(STDIN_FILENO, "HELLO", 5);

    if(-1 == write(pipefd[1], "hello", 5))
    {
        perror("write");
        exit(1);
    }

    pid_t pid = fork();
    if(pid == 0)
    {
        printf("hello\n");
        execlp("ps", "ps", "-aux", NULL);
        perror("execlp");
        exit(1);
    }
    if(pid > 0)
    {
        sleep(1);
        execlp("grep","grep", "bash",NULL);
        perror("execlp");
        exit(1);
    }

}
