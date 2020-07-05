#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int ret;
    int fd;
    char info[] = "what's your name.";
    ret = access("./fifo", F_OK);
    if(ret == -1)
    { 
        ret = mkfifo("./fifo", 0400|0200|0040|0004);
        if(ret == -1)
        {
            perror("mkfifo");
            exit(1);
        }
    }

    fd = open("./fifo", O_WRONLY);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }

    while(1)
    {
        printf("write:%ld\n",write(fd, info, sizeof(info)));
        sleep(1);
    }
    
    close(fd);
    return 0;
}
