# include "head.h"

void	mandelbrot_loop_thread(t_mlx *mlx, t_complex zn, int start, int end)
{
	int			iter;
	int			color;
	int			pa;
	int			pb;
	float		pa_step;
	float		pb_step;
	float		f_end;
	float		f_start;
	t_complex	c;
	t_complex	pos;

	pa_step = (float)(mlx->d.end.real - mlx->d.start.real) / (float)mlx->width;
	pb_step = (float)(mlx->d.end.imag - mlx->d.start.imag) / (float)mlx->height;
	f_start = pix_to_math(start, mlx->width, mlx->d.start.real, mlx->d.end.real);
	f_end = pix_to_math(end, mlx->width, mlx->d.start.real, mlx->d.end.real);
	color = 0;
	c.real = mlx->c.real;
	c.imag = mlx->c.imag;
	pa = start;
	pos.real = f_start;
	while (pos.real < f_end)
	{
		pb = 0;
		pos.imag = mlx->d.start.imag;
		while (pos.imag <  mlx->d.end.imag)
		{
			iter = 0;
			zn.real = pos.real;
			zn.imag = pos.imag;
			if (mlx->mandelbrot)
			{
				c.real = pos.real;
				c.imag = pos.imag;
			}
			while (iter < mlx->max_iter && mandelbrot_equation(&zn, &c) == TRUE)
				iter++;
			if (1 || !mlx->free_julia)
				color = colorize_fractol(iter, mlx);
			else
				if (iter < mlx->max_iter)
					color = ft_get_color(0,
						((float)iter / (float)mlx->max_iter) * 255,
						((float)iter / (float)mlx->max_iter) * 255,
						((float)iter / (float)mlx->max_iter) * 255);
				else
					color = 0x00ffffff;
			ft_color_pixel(mlx, pa, pb, color);
			pos.imag = pos.imag + pb_step;
			pb++;
		}
		pos.real = pos.real + pa_step;
		pa++;
	}
}
