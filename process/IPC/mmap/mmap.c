#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd;
    void* fp;
    fd = open("./file.txt", O_RDWR);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }

    fp = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
    if(fp == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    printf("%s\n", fp);

    munmap(fp, 0);
    close(fd);
    return 0;
}
