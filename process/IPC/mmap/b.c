#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int fd;
    void* fp;
    char* mov_fp;
    fd = open("./file.txt", O_RDWR);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }

    fp = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(fp == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    
    printf("%s\n", fp);

    int ret = munmap(fp,136 );
    if(ret == -1)
    {
        perror("munmap");
    }
    close(fd);
    return 0;
}
