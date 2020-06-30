/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2020/06/30 23:08:19 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			mouse_press(int button, int x, int y, t_mlx *param)
{
	printf("mouse p %d\n", button);
	param->mouse_array[button][MLX_MOUSE_PRESSED] = TRUE;
	param->mouse_array[button][MLX_MOUSE_X_COORD] = x;
	param->mouse_array[button][MLX_MOUSE_Y_COORD] = y;
	if (button == MLX_MOUSE_SCROLL_UP
	|| button == MLX_MOUSE_SCROLL_DOWN)
	{
		zoom(button, x, y, param);
		thread_fractol(param, NB_THREAD);
	}
	render(param);
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *param)
{
	printf("mouse r %d\n", button);
	param->mouse_array[button][MLX_MOUSE_PRESSED] = FALSE;
	param->mouse_array[button][MLX_MOUSE_X_COORD] = x;
	param->mouse_array[button][MLX_MOUSE_Y_COORD] = y;
	if (button == 1)
	{
		ft_color_pixel(param, x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	if (button == 3)
		ft_dynamic_rectangle(param, ft_get_point(x, y));
	return (1);
}

int mouse_move(int x, int y, t_mlx *param)
{

	if (param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_PRESSED] == TRUE)
		move_content_window(param, x, y);
	if (!param->mandelbrot && param->free_julia)
		julia_react_to_mouse(param, x, y);
	return (1);
}
