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

int key_press(int keycode, t_mlx *mlx)
{
	ft_printf("KEY[%d] %d\n", MLX_KEYS_OS, keycode);
	if (keycode < 280)
	{
		mlx->key_array[keycode] = 1;
		if (keycode == MLX_KEY_M)
			mlx->mandelbrot = !mlx->mandelbrot;
		if (keycode == MLX_KEY_SPACE)
			mlx->free_julia = !mlx->free_julia;
	}
	if (keycode == MLX_KEY_PLUS)
		mlx->max_iter += 1;
	if (keycode == MLX_KEY_MINUS && mlx->max_iter > 1)
		mlx->max_iter -= 1;
	if (keycode == MLX_KEY_LEFT)
		arrow_slide_screen(mlx, 1, 0);
	if (keycode == MLX_KEY_UP)
		arrow_slide_screen(mlx, 0, 1);
	if (keycode == MLX_KEY_RIGHT)
		arrow_slide_screen(mlx, -1, 0);
	if (keycode == MLX_KEY_DOWN)
		arrow_slide_screen(mlx, 0, -1);

	if (keycode == MLX_KEY_ESCAPE)
	{
		exit(0);
		ft_clean_and_exit(mlx);
	}
	if (keycode == MLX_KEY_DELETE)
		virgin_screen(mlx);
	thread_fractol(mlx, NB_THREAD);
	render(mlx);
	return (0);
}

int key_release(int keycode, t_mlx *mlx)
{
	mlx->key_array[keycode] = 0;
	return (0);
}
