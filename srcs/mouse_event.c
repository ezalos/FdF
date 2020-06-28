/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2020/06/29 01:13:23 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			mouse_press(int button, int x, int y, t_mlx *param)
{
	printf("mouse p %d\n", button);
	param->mouse_array[button][0] = 1;
	param->mouse_array[button][1] = x;
	param->mouse_array[button][2] = y;
	if (button == 5 || button == 4)
	{
		zoom(button, x, y, param);
		fractol_thread(param, NB_THREAD);
	}
	render(param);
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *param)
{
	printf("mouse r %d\n", button);
	param->mouse_array[button][0] = 0;
	param->mouse_array[button][1] = x;
	param->mouse_array[button][2] = y;
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
	height = param->d.end.b - param->d.start.b;
	width = param->d.end.a - param->d.start.a;
	////
	f_x = pix_to_math(x, param->width, 0, height);
	f_y = pix_to_math(y, param->height, 0, width);
	ft_printf("\t-> %f %f\n", f_x, f_y);
	////
	////
	param->d.start.a = param->d.start.a + f_y;
	param->d.end.a   = param->d.end.a + f_y;
	param->d.start.b = param->d.start.b + f_x;
	param->d.end.b   = param->d.end.b + f_x;
	////
}

int mouse_move(int x, int y, t_mlx *param)
{
	static int	last = 0;

	if (param->mouse_array[1][0] == 1)
	{
		if (!last)
		{
			move_complex_window_center(param,
				param->mouse_array[1][1] - x, param->mouse_array[1][2] - y);
			fractol_thread(param, NB_THREAD);
			render(param);
			param->mouse_array[1][1] = x;
			param->mouse_array[1][2] = y;
		}
		else
			last++;
		if (last > 5)
			last = 0;
	}
	if (!param->mandelbrot && param->free_julia)
	{

		// ft_printf("STE %d\n", last);
		if (!last)
		{
			// ft_printf("MOVE [%d %d]\n", x ,y);
			param->c.a = pix_to_math(x, param->width, -2, 2);
			param->c.b = pix_to_math(y, param->height, -2, 2);
			fractol_thread(param, NB_THREAD);
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
