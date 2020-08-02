
#include "head.h"

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
