#include <stdio.h>
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

    fp = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
    if(fp == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);

    mov_fp = fp;

   char ch[] = "hello world\n";
   int b = 0;
  for(int i = 0; ; i++)
  {

      b = i % sizeof(ch);
      printf("%d / %d = %d\n", i, sizeof(ch), b);
      if(i == 1024)
      {
          break;
      }
     *mov_fp = ch[b];
      mov_fp ++;
  } 

    printf("%s\n", fp);

    int ret = munmap(fp,136 );
    if(ret == -1)
    {
        perror("munmap");
    }
    close(fd);
    return 0;
}
