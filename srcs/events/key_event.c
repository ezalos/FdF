/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:07 by amartino          #+#    #+#             */
/*   Updated: 2020/07/01 00:21:19 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
	if (keycode == MLX_KEY_PLUS)
		param->max_iter += 1;
	if (keycode == MLX_KEY_MINUS && param->max_iter > 1)
		param->max_iter -= 1;
	if (keycode == MLX_KEY_LEFT)
		arrow_slide_screen(param, 1, 0);
	if (keycode == MLX_KEY_UP)
		arrow_slide_screen(param, 0, 1);
	if (keycode == MLX_KEY_RIGHT)
		arrow_slide_screen(param, -1, 0);
	if (keycode == MLX_KEY_DOWN)
		arrow_slide_screen(param, 0, -1);

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
