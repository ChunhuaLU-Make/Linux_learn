#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int flag = -1;
    struct stat FileInfo;

    if(argc == 2)
    {
        flag = stat(argv[1],&FileInfo);
    }
    else
    {
        printf("Please input file name\n");
    }
    
    printf("st_mode:%x\n",FileInfo.st_mode);
    printf("Inode:%ld\n", FileInfo.st_ino);

    return 0;
}
