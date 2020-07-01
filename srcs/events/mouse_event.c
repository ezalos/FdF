/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2020/07/01 02:23:24 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			mouse_press(int button, int x, int y, t_mlx *mlx)
{
	printf("mouse p %d\n", button);
	mlx->keys.mouse_array[button][MLX_MOUSE_PRESSED] = TRUE;
	mlx->keys.mouse_array[button][MLX_MOUSE_X_COORD] = x;
	mlx->keys.mouse_array[button][MLX_MOUSE_Y_COORD] = y;
	if (button == MLX_MOUSE_SCROLL_UP
	|| button == MLX_MOUSE_SCROLL_DOWN)
	{
		zoom(button, x, y, mlx);
		thread_fractol(mlx, NB_THREAD);
	}
	render(mlx);
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *mlx)
{
	printf("mouse r %d\n", button);
	mlx->keys.mouse_array[button][MLX_MOUSE_PRESSED] = FALSE;
	mlx->keys.mouse_array[button][MLX_MOUSE_X_COORD] = x;
	mlx->keys.mouse_array[button][MLX_MOUSE_Y_COORD] = y;
	return (1);
}


long		get_time(void)
{
	long            ns;
	time_t          s;
	struct timespec spec;
	long            ms;

	clock_gettime(CLOCK_REALTIME, &spec);
	s = spec.tv_sec;
	ns = spec.tv_nsec;
	ms = (s * 1000 + ns / 1000000);
	return (ms);
}

int mouse_move(int x, int y, t_mlx *mlx)
{
	static long		time = 0;

	if (time == 0)
		time = get_time();
	if (get_time() - time < 1000 / 200)//avoid to flood computer with calculs 
		return (0);

	time = get_time();
	if (mlx->keys.mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_PRESSED] == TRUE)
		move_content_window(mlx, x, y);
	if (!mlx->fractal.mandelbrot && mlx->fractal.free_julia)
		julia_react_to_mouse(mlx, x, y);
	return (1);
}
