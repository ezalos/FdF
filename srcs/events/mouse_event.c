/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2020/06/30 19:32:36 by ezalos           ###   ########.fr       */
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

//is way too slow
void	move_complex_window_center(t_mlx *param, int y, int x)
{
	float	height;
	float 	width;
	float	f_x;
	float 	f_y;

	ft_printf("Moving %d %d", x, y);
	////
	height = param->d.end.imag - param->d.start.imag;
	width = param->d.end.real - param->d.start.real;
	////
	f_x = pix_to_math(x, param->width, 0, width);
	f_y = pix_to_math(y, param->height, 0, height);
	ft_printf("\t-> %f %f\n", f_x, f_y);
	////
	////
	param->d.start.real = param->d.start.real + f_y;
	param->d.end.real   = param->d.end.real + f_y;
	param->d.start.imag = param->d.start.imag + f_x;
	param->d.end.imag   = param->d.end.imag + f_x;
	////
}

int mouse_move(int x, int y, t_mlx *param)
{
	static int	last = 0;

	if (param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_PRESSED] == 1)
	{
		if ((ft_abs(param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD] - x) > 10
		&& ft_abs(param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD] - y) > 10))
		{
			move_complex_window_center(param,
				param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD] - x,
				param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD] - y);
			thread_fractol(param, NB_THREAD);
			render(param);
			param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD] = x;
			param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD] = y;
		}
		else
			last++;
		if (last > 25)
			last = 0;
	}
	if (!param->mandelbrot && param->free_julia)
	{

		// ft_printf("STE %d\n", last);
		if (!last)
		{
			// ft_printf("MOVE [%d %d]\n", x ,y);
			param->c.real = pix_to_math(x, param->width, -2, 2);
			param->c.imag = pix_to_math(y, param->height, -2, 2);
			thread_fractol(param, NB_THREAD);
			render(param);
			last++;
		}
		else
			last++;
		if (last > 5)
			last = 0;
	}
	return (1);
}
