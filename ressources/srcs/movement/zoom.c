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
	height = mlx->d.end.imag - mlx->d.start.imag;
	width = mlx->d.end.real - mlx->d.start.real;
	////
	new_height = height - ((height * ZOOM_COEF) * direction);
	new_width = width - ((width * ZOOM_COEF) * direction);
	////
	x = pix_to_math(x, mlx->width, mlx->d.start.real, mlx->d.end.real);
	y = pix_to_math(y, mlx->height, mlx->d.start.imag, mlx->d.end.imag);
	////
	start_to_x = (x - mlx->d.start.real) / width;
	start_to_y = (y - mlx->d.start.imag) / height;
	////
	mlx->d.start.real = x - (new_width * start_to_x);
	mlx->d.end.real   = mlx->d.start.real + new_width;
	mlx->d.start.imag = y - (new_height * start_to_y);
	mlx->d.end.imag   = mlx->d.start.imag + new_height;
	////
}
