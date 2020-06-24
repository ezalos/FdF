/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:19:28 by deyaberg          #+#    #+#             */
/*   Updated: 2020/06/24 16:12:34 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			which_one(int direction)
{
	if (direction == Z_FORWARD)
		direction = 1;
	else
		direction = -1;
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
	height = param->d.end.b - param->d.start.b;
	width = param->d.end.a - param->d.start.a;
	////
	new_height = height - ((height * ZOOM_COEF) * direction);
	new_width = width - ((width * ZOOM_COEF) * direction);
	////
	x = pix_to_math(x, param->width, param->d.start.a, param->d.end.a);
	y = pix_to_math(y, param->height, param->d.start.b, param->d.end.b);
	////
	start_to_x = (x - param->d.start.a) / width;
	start_to_y = (y - param->d.start.b) / height;
	////
	param->d.start.a = x - (new_width * start_to_x);
	param->d.end.a   = param->d.start.a + new_width;
	param->d.start.b = y - (new_height * start_to_y);
	param->d.end.b   = param->d.start.b + new_height;
	////
}
