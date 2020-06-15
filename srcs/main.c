/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2020/06/15 10:11:51 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		mandelbrot_equation(t_complex *zn, t_complex *c)
{
	float	_i2;
	float	_2ix;
	float	_x2;

	_i2 = zn->i * zn->i;
	_x2 = zn->x * zn->x;
	_2ix = 2 * zn->x * zn->i;
	if (_i2)
		_x2 = -1 * _x2 * _i2;
	zn->i = _2ix + c->i;
	zn->x = _x2 + c->x;
	if (sqrt((zn->x * zn->x) + (zn->i * zn->i)) > 2)
		return (TRUE);
	return (FALSE);
}

// void	mandelbrot_loop(t_mlx *mlx)
// {
// 	t_complex	zn;
// 	t_complex	c;
// 	int			x;
//
// }


int		main(int ac, char **av)
{
	t_mlx			*mlx;
//	int				color;

	if (ac < 2 && ac > 4)
		return (0);
	if (!(mlx = ft_init_mlx(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();
	// if (fdf_parsing(av[1], mlx) == 0)
	// 	ft_clean_garbage();
//	color = ft_get_color(0, 0, 0, 0);
	ft_draw_circle(mlx, mlx->width / 2, mlx->height / 2, 500);
	mlx_hook(mlx->window_pointer, 2, 1L<<0, key_press, mlx);
	mlx_hook(mlx->window_pointer, 3, 1L<<1, key_release, mlx);
	mlx_hook(mlx->window_pointer, 4, 1L<<2, mouse_press, mlx);
	mlx_hook(mlx->window_pointer, 5, 1L<<3, mouse_release, mlx);
	mlx_hook(mlx->window_pointer, 6, 1L<<6, mouse_move, mlx);
	mlx_loop(mlx->mlx_pointer);
	return (0);
}
