/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2020/06/29 01:14:32 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

float	pix_to_math(float pixel, float size, float start, float end)
{
	float small;

	small = start + ((pixel / size) * (end - start));
	return (small);
}

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

	pa_step = (float)(mlx->d.end.a - mlx->d.start.a) / (float)mlx->width;
	pb_step = (float)(mlx->d.end.b - mlx->d.start.b) / (float)mlx->height;
	f_start = pix_to_math(start, mlx->width, mlx->d.start.a, mlx->d.end.a);
	f_end = pix_to_math(end, mlx->width, mlx->d.start.a, mlx->d.end.a);
	color = 0;
	c.a = mlx->c.a;
	c.b = mlx->c.b;
	pa = start;
	pos.a = f_start;
	while (pos.a < f_end)
	{
		pb = 0;
		pos.b = mlx->d.start.b;
		while (pos.b <  mlx->d.end.b)
		{
			iter = 0;
			zn.a = pos.a;
			zn.b = pos.b;
			if (mlx->mandelbrot)
			{
				c.a = pos.a;
				c.b = pos.b;
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
			pos.b = pos.b + pb_step;
			pb++;
		}
		pos.a = pos.a + pa_step;
		pa++;
	}
}

int		parsing_fractol(int ac, char **av)
{
	parse_new("fractol", "display a swaggy fractal");

	parse_add_option('M', "Mandelbrot",	"Display Mandelbrot Fractal");
	parse_add_option('o', "Movement",	"Julia movement Fractal");
	parse_add_option('J', "Julia",	"Display Julia ensemble Fractal");
	if (parse_args(ac, av) == FAILURE)
		return (FAILURE);
	if (parse_get("help") != NULL)
	{
		parse_usage();
		return (FAILURE);
	}
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	t_mlx			*mlx;

	if (parsing_fractol(ac, av) == FAILURE)
		return (FAILURE);
	if (!(mlx = ft_init_mlx(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();
//	set_up_palettes(mlx);
	fractol_thread(mlx, NB_THREAD);
	render(mlx);
	mlx_hook(mlx->window_pointer, 2, 1L<<0, key_press, mlx);
	mlx_hook(mlx->window_pointer, 3, 1L<<1, key_release, mlx);
	mlx_hook(mlx->window_pointer, 4, 1L<<2, mouse_press, mlx);
	mlx_hook(mlx->window_pointer, 5, 1L<<3, mouse_release, mlx);
	mlx_hook(mlx->window_pointer, 6, 1L<<6, mouse_move, mlx);
	mlx_loop(mlx->mlx_pointer);
	return (0);
}
