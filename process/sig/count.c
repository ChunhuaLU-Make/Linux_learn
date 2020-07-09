#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    alarm(1);
    while(1)printf("%d\n",i++);
   return 0;
}
