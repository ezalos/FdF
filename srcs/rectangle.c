/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:32:24 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/12 23:02:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	ft_draw_rectangle(t_mlx *mlx, t_point *a, t_point *b, unsigned int color)
{
	int		x0;
	int		x1;
	int		x;
	int		y0;
	int		y1;
	int		y;

	if (a->x < b->x)
	{
		x0 = a->x;
		x1 = b->x;
	}
	else
	{
		x0 = b->x;
		x1 = a->x;
	}
	if (a->y < b->y)
	{
		y0 = a->y;
		y1 = b->y;
	}
	else
	{
		y0 = b->y;
		y1 = a->y;
	}
	y = y0 - 1;
	while (++y <= y1)
	{
		x = x0 - 1;
		while (++x <= x1)
			ft_color_pixel(mlx, x, y, color);
	}
}

void	ft_dynamic_rectangle(t_mlx *mlx, t_point *a)
{
	static t_point	*p;

	if (!p)
		p = a;
	else
	{
		ft_draw_rectangle(mlx, p, a, mlx->saved_color);
		ft_memdel((void**)&p);
		render(mlx);
	}
}
