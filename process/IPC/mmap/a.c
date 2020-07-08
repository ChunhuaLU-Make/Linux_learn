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
    fd = open("./file.txt", O_RDWR | O_CREAT, 0600);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    
    truncate("./file.txt", 4096);

    off_t off = lseek(fd, 0, SEEK_END); 

    printf("file size:%d\n", off);

    fp = mmap(NULL, off, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(fp == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    
    while(1)
    {
        strcpy(fp, "what you brithday");
        sleep(1);
    }   

    int ret = munmap(fp,off);
    if(ret == -1)
    {
        perror("munmap");
    }
    close(fd);
    return 0;
}
