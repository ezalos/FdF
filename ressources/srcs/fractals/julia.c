
#include "head.h"

void	julia_react_to_mouse(t_mlx *mlx, int x, int y)
{
	static int	last = 0;

	if (!last)
	{
		mlx->c.real = pix_to_math(x, mlx->width, -2, 2);
		mlx->c.imag = pix_to_math(y, mlx->height, -2, 2);
		thread_fractol(mlx, NB_THREAD);
		render(mlx);
		last++;
	}
	else
		last++;
	if (last > 5)
		last = 0;
}
