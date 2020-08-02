/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:07 by amartino          #+#    #+#             */
/*   Updated: 2020/07/02 12:29:24 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int key_press(int keycode, t_mlx *mlx)
{
	ft_printf("KEY[%d] %d\n", MLX_KEYS_OS, keycode);
	if (keycode < 280)
	{
		mlx->keys.key_array[keycode] = 1;
		if (keycode == MLX_KEY_M)
		{
			if (!mlx->fractal.mandelbrot)
			{
				mlx->fractal.dimension.start.real -= 0.5;
				mlx->fractal.dimension.end.real   -= 0.5;
			}
			else
			{
				mlx->fractal.dimension.start.real += 0.5;
				mlx->fractal.dimension.end.real   += 0.5;
			}
			mlx->fractal.mandelbrot = !mlx->fractal.mandelbrot;
		}
		if (keycode == MLX_KEY_SPACE)
			mlx->fractal.free_julia = !mlx->fractal.free_julia;
	}
	if (keycode == MLX_KEY_PLUS)
		mlx->fractal.max_iter += 1;
	if (keycode == MLX_KEY_MINUS && mlx->fractal.max_iter > 1)
		mlx->fractal.max_iter -= 1;

	if (anti_flood())
		return (0);
	if (keycode == MLX_KEY_LEFT)
		arrow_slide_screen(mlx, 1, 0);
	if (keycode == MLX_KEY_UP)
		arrow_slide_screen(mlx, 0, 1);
	if (keycode == MLX_KEY_RIGHT)
		arrow_slide_screen(mlx, -1, 0);
	if (keycode == MLX_KEY_DOWN)
		arrow_slide_screen(mlx, 0, -1);
	if (keycode == MLX_KEY_R)
		init_values(mlx);

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
	mlx->keys.key_array[keycode] = 0;
	return (0);
}
