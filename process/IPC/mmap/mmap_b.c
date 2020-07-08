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

    fp = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON,-1,0);
    if(fp == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    
    strcpy(fp, "You is dog");

    int ret = munmap(fp, 4096);
    if(ret == -1)
    {
        perror("munmap");
    }
    close(fd);
    return 0;
}
