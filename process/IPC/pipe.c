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
    dup2(pipefd[1], STDOUT_FILENO);
    char ch;

    while(read(STDOUT_FILENO, &ch, 1) != 0)
    {
        write(STDIN_FILENO, &ch, 1);
    }

#if 0
    if(-1 == write(pipefd[1], "hello", 5))
    {
        perror("write");
        exit(1);
    }

    char buf;
    while(0 != read(pipefd[0], &buf, 1))
    {
        printf("%c",buf);
    }
    printf("\n");

    pid_t pid = fork();
    if(pid == 0)
    {
        execlp("ps", "ps", "-aux", NULL);
        perror("execlp");
        exit(1);
    }
    if(pid > 0)
    {
        execlp("grep","grep", "bash",NULL);
        perror("execlp");
        exit(1);
    }
#endif

}
