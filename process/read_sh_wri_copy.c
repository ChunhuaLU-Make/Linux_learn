#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

int temp = 100;

int main()
{
    int i = 0;
    pid_t pid;
    uint8_t pid_flage = 0xff;

    for(i = 0; i < 2; i++)
    {
        pid = fork();
        if(pid == 0)
        {
            break;
        }
        /* for loop end ++ */
    }
    
    /* Create lost of brother  process */
    if(i == 0)
    {
        pid_flage = 1;
        printf("temp address:0x%x\n", &temp);
        temp = 1000;
        printf("write temp address:0x%x\n",&temp);
        sleep(1);
    }

    if(i == 1)
    {
        pid_flage = 2;
        printf("father temp address:0x%x\n", &temp);
        temp = 2000;
        printf("write father address:0x%x\n", &temp);
        sleep(1);
    }

    if(i == 2)
    {
        /* This is a father process */
        printf("3 child:%d father:%d\n", getpid(),getppid());
    }
    sleep(10);
    if(pid_flage == 1)
    {
        printf("temp 1:%d\n", temp);
    }
    else if(pid_flage == 2)\
    {
        printf("temp 2:%d\n", temp);
    }
    printf("temp :%d\n", temp);
    return 0;
}
