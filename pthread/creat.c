#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int num;
void* thread_one(void* arg)
{
	printf("one self is :%d\n", *(int*)arg);
	*(int*)arg++;
	num ++;
	printf("num:%d\n", num);
}


int main()
{
	//循环创建5个线程分别把5个线程的序号打印出来
	
	pthread_t thread;
	int count = 0;
	for(int i = 0; i < 5; i++)
	{
		pthread_create(&thread, NULL, thread_one, &count);
	}
	sleep(1);
	return 0;
}
