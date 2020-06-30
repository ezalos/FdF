/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:19:28 by deyaberg          #+#    #+#             */
/*   Updated: 2020/06/30 18:14:05 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			which_one(int direction)
{
	if (direction == Z_FORWARD)
		direction = 1;
	else
		direction = -1;
	if (!MLX_KEYS_OS)
		direction = -direction;
	return (direction);
}

void		zoom(int direction, float x, float y, t_mlx *param)
{
	float	height;
	float 	width;
	float	new_height;
	float	new_width;
	float	start_to_x;
	float	start_to_y;

	direction = which_one(direction);
	////
	height = param->d.end.imag - param->d.start.imag;
	width = param->d.end.real - param->d.start.real;
	////
	new_height = height - ((height * ZOOM_COEF) * direction);
	new_width = width - ((width * ZOOM_COEF) * direction);
	////
	x = pix_to_math(x, param->width, param->d.start.real, param->d.end.real);
	y = pix_to_math(y, param->height, param->d.start.imag, param->d.end.imag);
	////
	start_to_x = (x - param->d.start.real) / width;
	start_to_y = (y - param->d.start.imag) / height;
	////
	param->d.start.real = x - (new_width * start_to_x);
	param->d.end.real   = param->d.start.real + new_width;
	param->d.start.imag = y - (new_height * start_to_y);
	param->d.end.imag   = param->d.start.imag + new_height;
	////
}
