
#include "head.h"

void	julia_react_to_mouse(t_mlx *param, int x, int y)
{
	static int	last = 0;

	if (!last)
	{
		param->c.real = pix_to_math(x, param->width, -2, 2);
		param->c.imag = pix_to_math(y, param->height, -2, 2);
		thread_fractol(param, NB_THREAD);
		render(param);
		last++;
	}
	else
		last++;
	if (last > 5)
		last = 0;
}
