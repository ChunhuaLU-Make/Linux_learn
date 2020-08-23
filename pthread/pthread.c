#include <stdio.h>
#include <pthread.h>

int num = 0;

void* and_total(void* arg)
{
	for(int i = 0; i < 5000; i++)
	{
		num++;
		printf("%c : %d\n", (char)arg, num);
		usleep(100);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread;
	pthread_t temp;
	
	for(int i = 0; i < 2; i++)
	{
		pthread_create(&thread, NULL, and_total, (void*)('a'+ i));
		if(i == 0)temp = thread;
	}
	pthread_join(temp, NULL);
	pthread_join(thread, NULL);
	printf("num:%d\n", num);
	return 0;
}
