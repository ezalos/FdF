/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:07 by amartino          #+#    #+#             */
/*   Updated: 2020/06/24 16:27:39 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void		shifties(t_mlx *mlx, int x, int y)
{
	float		width;
	float		shift_width;
	float		height;
	float		shift_height;

	width = (mlx->d.end.a - mlx->d.start.a);
	height = (mlx->d.end.b - mlx->d.start.b);
	shift_width = ZOOM_COEF * width;
	shift_height = ZOOM_COEF * height;
	ft_printf("Shift [%f %f]\n", shift_height, shift_width);
	if (x < 0)
		shift_width = -shift_width;
	else if (x == 0)
		shift_width = 0;
	if (y < 0)
		shift_height = -shift_height;
	else if (y == 0)
		shift_height = 0;
	ft_printf("Shift [%f %f]\n", shift_height, shift_width);
	mlx->d.start.a += shift_width;
	mlx->d.end.a += shift_width;
	mlx->d.start.b += shift_height;
	mlx->d.end.b += shift_height;
}

int key_press(int keycode, t_mlx *param)
{
	ft_printf("KEY %d\n", keycode);
	if (keycode < 280)
	{
		param->key_array[keycode] = 1;
		if (keycode == ESC)
			ft_clean_and_exit(param);
		if (keycode == DEL)
			virgin_screen(param);
		if (keycode == 109)//M
			param->mandelbrot = !param->mandelbrot;
		if (keycode == 32)//SPACE
			param->free_julia = !param->free_julia;
	}
	if (keycode == 65361)//left
		shifties(param, 1, 0);
	if (keycode == 65362)//up
		shifties(param, 0, 1);
	if (keycode == 65363)//right
		shifties(param, -1, 0);
	if (keycode == 65364)//up
		shifties(param, 0, -1);

	mandel_thread(param, 8);
	render(param);
	return (0);
}

int key_release(int keycode, t_mlx *param)
{
	param->key_array[keycode] = 0;
	return (0);
}
