#include "head.h"

long		get_time(void)
{
	long            ns;
	time_t          s;
	struct timespec spec;
	long            ms;

	clock_gettime(CLOCK_REALTIME, &spec);
	s = spec.tv_sec;
	ns = spec.tv_nsec;
	ms = (s * 1000) + (ns / 1000000);
	return (ms);
}

int			anti_flood(void)
{
	static long		time = 0;

	if (time == 0)
		time = get_time();
	if (get_time() - time < 1000 / 200)//avoid to flood computer with calculs
	{
		ft_printf("Anti flood!\n");
		return (1);
	}
	time = get_time();
	return (0);
}
