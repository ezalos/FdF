/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2020/06/23 18:28:21 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		mandelbrot_equation(t_complex *zn, t_complex *c)
{
	float	a_sqr;
	float	b_sqr;
	float	two_ab;
	float	real;


	// Zn+1 = Zn^2 + c
	a_sqr = zn->a * zn->a;
	b_sqr = zn->b * zn->b;
	two_ab = 2 * zn->b * zn->a;
	real = a_sqr + (-1 * b_sqr);
	zn->a = real + c->a;
	zn->b = two_ab + c->b;
	if (zn->a > 2 || zn->b > 2 || zn->a < -2 || zn->b < -2
	|| sqrt((zn->a * zn->a) + (zn->b * zn->b)) > 2)
		return (FALSE);
	return (TRUE);
}

float	pix_to_math(float pixel, float size, float start, float end)
{
	float small;

	small = start + ((pixel / size) * (end - start));
	return (small);
}

int		colorize_fractol(int iter)
{
	int		color;

	if (iter == 0)
		color = ft_get_color(0, 204 + iter % 20, 153, 0);
	else if (iter > 0 && iter % 10 < 2)
		color = 0;
	else if (iter % 10 >= 2 && iter % 10 < 4)
		color = ft_get_color(0, 204 + iter % 20, 102, 0);
	else if (iter % 10 >= 4 && iter % 10 < 6)
		color = ft_get_color(0, 255, 255, 150 + iter % 20);
	else if (iter % 10 >= 6 && iter % 10 < 8)
		color = ft_get_color(0, 102, 0, 204);
	else
		color = 0;
	return (color);
}

void	mandelbrot_loop(t_mlx *mlx)
{
	int			iter;
	int			color;
	float		pa;
	float		pb;

	pa = 0;
	while (pa < mlx->width)
	{
		pb = 0;
		while (pb < mlx->height)
		{
			iter = 0;
			mlx->zn.a = pix_to_math(pa, mlx->width, mlx->d.start.a, mlx->d.end.a);
			mlx->zn.b = pix_to_math(pb, mlx->height, mlx->d.start.b, mlx->d.end.b);
	//		if (mlx->mandelbrot)
	//		{
				mlx->c.a = mlx->zn.a;
				mlx->c.b = mlx->zn.b;
	//		}
			while (iter < MAX_ITER && mandelbrot_equation(&mlx->zn, &mlx->c) == TRUE)
				iter++;
			color = colorize_fractol(iter);
			ft_color_pixel(mlx, pa, pb, color);
			pb++;
		}
		pa++;
	}
}


int		main(int ac, char **av)
{
	t_mlx			*mlx;

	if (ac < 2 && ac > 4)
		return (0);
	if (!(mlx = ft_init_mlx(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();
	mandelbrot_loop(mlx);
	render(mlx);
	// if (fdf_parsing(av[1], mlx) == 0)
	// 	ft_clean_garbage();
//	ft_draw_circle(mlx, mlx->width / 2, mlx->height / 2, 500);
	mlx_hook(mlx->window_pointer, 2, 1L<<0, key_press, mlx);
	mlx_hook(mlx->window_pointer, 3, 1L<<1, key_release, mlx);
	mlx_hook(mlx->window_pointer, 4, 1L<<2, mouse_press, mlx);
	mlx_hook(mlx->window_pointer, 5, 1L<<3, mouse_release, mlx);
	mlx_hook(mlx->window_pointer, 6, 1L<<6, mouse_move, mlx);
	mlx_loop(mlx->mlx_pointer);
	return (0);
}
