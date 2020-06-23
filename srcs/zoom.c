/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:07:55 by deyaberge         #+#    #+#             */
/*   Updated: 2020/06/23 16:39:48 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void		zoom(int direction, int x, int y, t_mlx *param)
{
	float	height;
	float 	width;
	float	new_height;
	float	new_width;
	float	start_to_x;
	float	start_to_y;

	if (direction == Z_FORWARD)
		direction = 1;
	else
		direction = -1;
	////
	height = param->d.end.b - param->d.start.b;
	width = param->d.end.a - param->d.start.a;
	////
	new_height = height - ((height * ZOOM_COEF) * direction);
	new_width = width - ((width * ZOOM_COEF) * direction);
	////
	ft_printf("x = %d, y = %d\n", x, y);
	x = pix_to_math(x, param->width, param->d.start.a, param->d.end.a);
	y = pix_to_math(y, param->height, param->d.start.b, param->d.end.b);
	////
	start_to_x = (x - param->d.start.a) / width;
	start_to_y = (x - param->d.start.b) / height;
	param->d.start.a = x - (new_width * start_to_x);
	param->d.end.a = new_width + param->d.start.a;
	param->d.start.b = y - (new_height * start_to_y);
	param->d.end.b = new_height + param->d.start.b;
	////
	mandelbrot_loop(param);
	render(param);
}
