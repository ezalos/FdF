
#include "head.h"

void	julia_react_to_mouse(t_mlx *mlx, int x, int y)
{
	static int	last = 0;

	if (!last)
	{
		mlx->fractal.c.real = pix_to_math(x, mlx->size.hori, -2, 2);
		mlx->fractal.c.imag = pix_to_math(y, mlx->size.vert, -2, 2);
		thread_fractol(mlx, NB_THREAD);
		render(mlx);
		mlx_string_put(mlx->mlx_pointer, mlx->window_pointer, 10, 10, 0xFFFFFF, "Live mouse movement");
		last++;
	}
	else
		last++;
	if (last > 5)
		last = 0;
}
