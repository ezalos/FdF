/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:07 by amartino          #+#    #+#             */
/*   Updated: 2020/06/30 18:16:12 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void		shifties(t_mlx *mlx, int x, int y)
{
	float		width;
	float		shift_width;
	float		height;
	float		shift_height;

	width = (mlx->d.end.real - mlx->d.start.real);
	height = (mlx->d.end.imag - mlx->d.start.imag);
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
	mlx->d.start.real += shift_width;
	mlx->d.end.real += shift_width;
	mlx->d.start.imag += shift_height;
	mlx->d.end.imag += shift_height;
}

int key_press(int keycode, t_mlx *param)
{
	ft_printf("KEY[%d] %d\n", MLX_KEYS_OS, keycode);
	if (keycode < 280)
	{
		param->key_array[keycode] = 1;
		if (keycode == MLX_KEY_M)
			param->mandelbrot = !param->mandelbrot;
		if (keycode == MLX_KEY_SPACE)
			param->free_julia = !param->free_julia;
	}
	if (keycode == MLX_KEY_LEFT)
		shifties(param, 1, 0);
	if (keycode == MLX_KEY_PLUS)
		param->max_iter += 1;
	if (keycode == MLX_KEY_MINUS && param->max_iter > 1)
		param->max_iter -= 1;
	if (keycode == MLX_KEY_UP)
		shifties(param, 0, 1);
	if (keycode == MLX_KEY_RIGHT)
		shifties(param, -1, 0);
	if (keycode == MLX_KEY_DOWN)
		shifties(param, 0, -1);

	if (keycode == MLX_KEY_ESCAPE)
	{
		exit(0);
		ft_clean_and_exit(param);
	}
	if (keycode == MLX_KEY_DELETE)
		virgin_screen(param);
	thread_fractol(param, NB_THREAD);
	render(param);
	return (0);
}

int key_release(int keycode, t_mlx *param)
{
	param->key_array[keycode] = 0;
	return (0);
}
