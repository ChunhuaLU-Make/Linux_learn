#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int ret;
    int fd;
    ssize_t num;
    char buffer[1024];
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

    fd = open("./fifo", O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }

    while(1)
    {
        num = read(fd, buffer, sizeof(buffer));
        if(num == 0)
        {
            continue;
        }
        printf("%s\n",buffer);
        memset(buffer, 0, sizeof(buffer));
        sleep(1);
    }
    
    close(fd);
    return 0;
}
