#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	sigset_t set;
	sigemptyset(&set);

	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	sigaddset(&set,SIGKILL);
	sigprocmask(SIG_BLOCK,&set, NULL);
	while(1)
	{
		sigpending(&set);
		for(int i = 1; i < 32; i++)
		{
			printf("%d",sigismember(&set, i));

		}		
		sleep(1);
		printf("\n");
	}

	return 0;
}
