/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:07:55 by deyaberge         #+#    #+#             */
/*   Updated: 2020/06/22 21:36:41 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	mandelbrot_loop(t_mlx *mlx);

void		zoom(int direction, int x, int y, t_mlx *param)
{
	float	height;
	float 	width;
	float	new_height;
	float	new_width;

	if (direction == Z_FORWARD)
		direction = 1;
	else
		direction = -1;
	height = param->d.end.a - param->d.start.a;
	width = param->d.end.b - param->d.start.b;
	new_height = height - ((height * ZOOM_COEF) * direction);
	new_width = width - ((width * ZOOM_COEF) * direction);
	param->d.end.a = x - ((new_height / 2) * direction);
	param->d.start.a = x + ((new_height / 2) * direction);
	param->d.end.b = y - ((new_width / 2) * direction);
	param->d.start.b = y + ((new_width / 2) * direction);
	mandelbrot_loop(param);
	render(param);
}
