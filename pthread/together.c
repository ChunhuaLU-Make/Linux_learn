#include <stdio.h>
#include <pthread.h>

int num = 0;
pthread_mutex_t mutex;

void* and_total(void* arg)
{
	for(int i = 0; i < 5000; i++)
	{
		pthread_mutex_lock(&mutex);
		num++;
		pthread_mutex_unlock(&mutex);
		printf("%c : %d\n", (char)arg, num);
		usleep(100);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread;
	pthread_t temp;
	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < 2; i++)
	{
		pthread_create(&thread, NULL, and_total, (void*)('a'+ i));
		if(i == 0)temp = thread;
	}
	pthread_join(temp, NULL);
	pthread_join(thread, NULL);
	printf("num:%d\n", num);
	pthread_mutex_destroy(&mutex);
	return 0;
}
