# include "head.h"

static void		prepare_fractal_arguments(t_multi_thread *thread)
{
	thread->zn.real = thread->pos.real;
	thread->zn.imag = thread->pos.imag;
	if (thread->mlx->fractal.mandelbrot)
	{
		thread->c.real = thread->pos.real;
		thread->c.imag = thread->pos.imag;
	}
}

static void		apply_color(t_multi_thread *thread, size_t iter)
{
	int			color;

	color = 0;
	if (thread->mlx->fractal.color_mode == 0)
		color = picasso(thread->mlx, iter, thread->zn);
	else if (thread->mlx->fractal.color_mode == 1)
		color = colorize_fractol(iter, thread->mlx);
	else if (thread->mlx->fractal.color_mode == 2)
		color = ft_get_color(0,
			((float)iter / (float)thread->mlx->fractal.max_iter) * 255,
			((float)iter / (float)thread->mlx->fractal.max_iter) * 255,
			((float)iter / (float)thread->mlx->fractal.max_iter) * 255);
	else
		color = 0x00ffffff;
	ft_color_pixel(thread->img, thread->pxl_width, thread->pxl_height, color);
}

void			fractal_loop_thread(t_multi_thread *thread)
{
	size_t		iter;

	thread->pxl_width = thread->start;
	thread->pos.real = thread->thread_start;
	while (thread->pos.real < thread->thread_end)
	{
		thread->pxl_height = 0;
		thread->pos.imag = thread->mlx->fractal.dimension.start.imag;
		while (thread->pos.imag < thread->mlx->fractal.dimension.end.imag)
		{
			iter = 0;
			prepare_fractal_arguments(thread);

			while (iter < thread->mlx->fractal.max_iter
			&& mandelbrot_equation(&thread->zn, &thread->c) == TRUE)
				iter++;

			apply_color(thread, iter);
			thread->pos.imag += thread->imag_step;
			thread->pxl_height++;
		}
		thread->pos.real += thread->real_step;
		thread->pxl_width++;
	}
}
