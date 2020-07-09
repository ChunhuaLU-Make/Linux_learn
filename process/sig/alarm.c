#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int ret = 0;
    ret = alarm(5);
    printf("return:%d\n", ret);
    
    sleep(3);
    ret = alarm(6);
    printf("return:%d\n", ret);

    while(1)
    {
        printf("I life\n");
        sleep(1);
    }
    return 0;
}
