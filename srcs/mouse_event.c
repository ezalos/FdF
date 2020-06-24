/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2020/06/24 16:12:28 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			mouse_press(int button, int x, int y, t_mlx *param)
{
	if (button == 1)
	{
		param->c.a = pix_to_math(x, param->width, param->d.start.a, param->d.end.a);
		param->c.b = pix_to_math(y, param->height, param->d.start.b, param->d.end.b);
	}
	if (button == 5 || button == 4)
		zoom(button, x, y, param);
	param->mouse_array[button] = 1;
	mandel_thread(param, 8);
	render(param);
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *param)
{
	// printf("mouse r %d\n", button);
	param->mouse_array[button] = 0;
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
	if (!param->mandelbrot && param->free_julia)
	{
		static int	last = 0;

		// ft_printf("STE %d\n", last);
		if (!last)
		{
			// ft_printf("MOVE [%d %d]\n", x ,y);
			param->c.a = pix_to_math(x, param->width, -2, 2);
			param->c.b = pix_to_math(y, param->height, -2, 2);
			mandel_thread(param, 8);
			last++;
		}
		else
			last++;
		if (last > 5)
			last = 0;
	}
	if (param->key_array[SHIFT] == 1)
	{
		// draw_lines_dynamically(x, y, param);
		ft_printf("SHIFT\n");
		// ft_color_pixel(param, x, y, 0x00ffffff);
		render(param);
	}
	return (1);
}
