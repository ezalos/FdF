/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:07:55 by deyaberge         #+#    #+#             */
/*   Updated: 2020/06/22 23:29:45 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	mandelbrot_loop(t_mlx *mlx);
float	pix_to_math(float pixel, float size, float min, float max);

void		zoom(int direction, int x, int y, t_mlx *param)
{
	float	height;
	float 	width;
	float	new_height;
	float	new_width;
	float	middle_a;
	float	middle_b;

	if (direction == Z_FORWARD)
		direction = 1;
	else
		direction = -1;
	////
	height = param->d.end.a - param->d.start.a;
	width = param->d.end.b - param->d.start.b;
	////
	new_height = height - ((height * ZOOM_COEF) * direction);
	new_width = width - ((width * ZOOM_COEF) * direction);
	////
	middle_a = new_height / 2;
	middle_b = new_width / 2;
	////
	ft_printf("x = %d, y = %d\n", x, y);
	param->d.end.a = x - (middle_a * direction);
	param->d.start.a = x + (middle_a * direction);
	param->d.end.b = y - (middle_b * direction);
	param->d.start.b = y + (middle_b * direction);
	////
	mandelbrot_loop(param);
	render(param);
}
