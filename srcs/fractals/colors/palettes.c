
#include "head.h"

int		*palette_dracula(void)
{
	int		*gradient;
	int		dracula_1 = 0x00DC2424;
	int		dracula_2 = 0x004A569D;

	gradient = ft_gradient(dracula_1, dracula_2, LEN_GRAD);
	return (gradient);
}

int		*palette_sunrise(void)
{
	int		*gradient;
	int		sunrise_1 = 0x00FF512F;
	int		sunrise_2 = 0x00F09819;

	gradient = ft_gradient(sunrise_1, sunrise_2, LEN_GRAD);
	return (gradient);
}

int		*palette_skyline(void)
{
	int		*gradient;
	int		skyline_1 = 0x001488CC;
	int		skyline_2 = 0x002B32B2;

	gradient = ft_gradient(skyline_1, skyline_2, LEN_GRAD);
	return (gradient);
}
