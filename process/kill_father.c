#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>  
#include <time.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void write_time()
{
	struct timeval tv;
	struct tm *gmt, *area;
	
	char time[1024] = { 0 };

	int fd = open("./file_time.txt", O_WRONLY| O_CREAT);
	if(fd == -1)
	{
		perror("errno");
		exit(1);
	}

	ssize_t length = 0;

	while(1)  
	{  
		gettimeofday(&tv,0);
		area = localtime(&(tv.tv_sec));//以本地时区显示时间
		sprintf(time, "Local time is: %s  %u:%u", asctime(area),tv.tv_sec,tv.tv_usec);
		length = write(fd, time, strlen(time));
		if(length != strlen(time))
		{
			printf("write file fail\n");
			exit(2);
		}

		sleep(1);
		//打印文件名和此段程序行数，并显示系统时间和微秒数；
		////printf("s: %u:%u\n",tv.tv_sec,tv.tv_usec);
		////gmt = gmtime(&(tv.tv_sec));//以GMT时区显示时间
		////printf("GMT is: %s", asctime(gmt));
		////　　
	}
	close(fd);
	//return 0;

}

int main()
{
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		exit(1);
	}
	else if(pid == 0)
	{
		setsid();
		write_time();
	}
}
