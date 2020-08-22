#include <stdio.h>
#include <signal.h>


void sig_function(int sig)
{
	printf("hell sig : %d\n", sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = sig_function;
	act.sa_flags = 0;
	while(1)
	sigaction(SIGINT, &act, NULL);
}
