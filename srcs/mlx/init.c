/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:33:41 by ldevelle          #+#    #+#             */
/*   Updated: 2020/08/02 17:57:58 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_abs_coord	ft_check_window_size(t_mlx *mlx, size_t width, size_t height)
{
	t_abs_coord		size;

	(void)mlx;
	if (!width)
		width = SIZE_WIDTH;
	if (!height)
		height = SIZE_HEIGTH;
	size.vert = height;
	size.hori = width;
	return(size);
}

void	*ft_open_mlx(t_mlx *mlx, char *title, t_abs_coord size)
{
	(void)mlx;
	(void)title;
	if ((mlx->window_pointer = mlx_new_window(mlx->mlx_pointer,\
		size.hori, size.vert, title)) == NULL)
		return (NULL);
	return (mlx);
}

void	init_values(t_mlx *mlx)
{
	mlx->fractal.dimension.start.real = -2.5;
	mlx->fractal.dimension.end.real = 2.5;
	mlx->fractal.dimension.start.imag = -2;
	mlx->fractal.dimension.end.imag = 2;
	// To be deleted //
	mlx->fractal.c.real = 0;
	mlx->fractal.c.imag = 0.75;
	mlx->fractal.max_iter = MAX_ITER;
	if (parse_get("Mandelbrot"))
		mlx->fractal.mandelbrot = 1;
	// if (parse_get("Movement"))
		mlx->fractal.free_julia = 1;
}

t_mlx		*ft_init_mlx(char *title, size_t width, size_t height)
{
	t_mlx			*mlx;
	t_abs_coord		pos;

	(void)title;
	mlx = ft_memalloc(sizeof(t_mlx));
	mlx->size = ft_check_window_size(mlx, width, height);
	if (!(mlx->mlx_pointer = mlx_init()))
		return (NULL);
	if (!ft_open_mlx(mlx, title, mlx->size))
		return (NULL);
	ft_bzero(&pos, sizeof(pos));
	if (!(ft_add_img(&mlx->images_manager, ft_create_img(mlx, "GLOBAL", mlx->size, pos))))
		return (NULL);
	init_values(mlx);
	return (mlx);
}
