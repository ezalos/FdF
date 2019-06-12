/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2019/06/10 20:57:17 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			mouse_press(int button, int x, int y, t_mlx *param)
{
	if (button == 1 && param->key_array[CONTROL] == 1)
		draw_lines_dynamically(x, y, param);
	param->mouse_array[button] = 1;
	if (button == 1)
	{
		ft_color_pixel(param, x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *param)
{
	param->mouse_array[button] = 0;
	if (button == 1)
	{
		ft_color_pixel(param, x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	return (1);
}

int mouse_move(int x, int y, t_mlx *param)
{
	if (param->key_array[SHIFT] == 1)
	{
		ft_color_pixel(param, x, y, 0x00ffffff);
		render(param);
	}
	return (1);
}
