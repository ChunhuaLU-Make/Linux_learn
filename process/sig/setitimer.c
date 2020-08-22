#include <stdio.h>
#include <sys/time.h>

int main()
{
	truct itimerval 
	{
		struct timeval it_interval; /* Interval for periodic timer */
		struct timeval it_value;    /* Time until next expiration */
	};

	struct timeval {
		time_t      tv_sec;         /* seconds */
		suseconds_t tv_usec;        /* microseconds */
	};

	setitimer(ITIMER_REAL, );
	return 0;
}
