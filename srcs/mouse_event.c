/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2020/06/18 00:58:35 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

float	get_small_dimension(float pixel, float size, float min, float max);
void	mandelbrot_loop(t_mlx *mlx);

int			mouse_press(int button, int x, int y, t_mlx *param)
{
	ft_printf("X %d & %d Y\n", x, y);
	param->c.a = get_small_dimension(x, param->width, param->d.re_start, param->d.re_end);
	param->c.b = get_small_dimension(y, param->height, param->d.im_start, param->d.im_end);
	ft_printf("C = %d + %d i\n", param->c.a, param->c.b);
	mandelbrot_loop(param);
	render(param);
	return (1);
	if (button == 1 && param->key_array[CONTROL] == 1)
		draw_lines_dynamically(x, y, param);
	// printf("mouse p %d\n", button);
	param->mouse_array[button] = 1;
	if (button == 1)
	{
		ft_draw_a_circle(param, x, y, param->circle_size, param->saved_color);
		render(param);
		return (1);
	}
	if (button == 2)
		param->saved_color = ft_get_color_pixel(param, x, y);
	if (button == 3)
		ft_dynamic_rectangle(param, ft_get_point(x, y));
	if (button == 4)
		param->circle_size++;
	if (button == 5)
		if (param->circle_size > 1)
			param->circle_size--;
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
	if (!param->mandelbrot && 0)
	{
		static double	last = 0;

		ft_printf("MANDEL %f\n", ((double)(last - clock())));
		if (!last || ((double)(last - clock())) < -60000)
		{
			last = ((double)(clock()));
			ft_printf("TIME\n");
			param->c.a = get_small_dimension(x, y, param->d.re_start, param->d.re_end);
			param->c.b = get_small_dimension(x, y, param->d.im_start, param->d.im_end);
			mandelbrot_loop(param);
			render(param);
		}
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
