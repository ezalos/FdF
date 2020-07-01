/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:19:28 by deyaberg          #+#    #+#             */
/*   Updated: 2020/06/30 23:06:31 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			which_one(int direction)
{
	if (direction == MLX_MOUSE_SCROLL_DOWN)
		direction = 1;
	else
		direction = -1;
	if (!MLX_KEYS_OS)
		direction = -direction;
	return (direction);
}

void		zoom(int direction, float x, float y, t_mlx *mlx)
{
	float	height;
	float 	width;
	float	new_height;
	float	new_width;
	float	start_to_x;
	float	start_to_y;

	direction = which_one(direction);
	////
	height = mlx->fractal.dimension.end.imag - mlx->fractal.dimension.start.imag;
	width = mlx->fractal.dimension.end.real - mlx->fractal.dimension.start.real;
	////
	new_height = height - ((height * ZOOM_COEF) * direction);
	new_width = width - ((width * ZOOM_COEF) * direction);
	////
	x = pix_to_math(x, mlx->width, mlx->fractal.dimension.start.real, mlx->fractal.dimension.end.real);
	y = pix_to_math(y, mlx->height, mlx->fractal.dimension.start.imag, mlx->fractal.dimension.end.imag);
	////
	start_to_x = (x - mlx->fractal.dimension.start.real) / width;
	start_to_y = (y - mlx->fractal.dimension.start.imag) / height;
	////
	mlx->fractal.dimension.start.real = x - (new_width * start_to_x);
	mlx->fractal.dimension.end.real   = mlx->fractal.dimension.start.real + new_width;
	mlx->fractal.dimension.start.imag = y - (new_height * start_to_y);
	mlx->fractal.dimension.end.imag   = mlx->fractal.dimension.start.imag + new_height;
	////
}
