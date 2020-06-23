/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:02:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/13 19:25:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_xone_equal_xtwo(t_mlx *mlx, t_line *line, int color)
{
	int		ymin;
	int		ymax;
	int		y;
	int		x;
	int		write;

	if (line->limits[0].y <= line->limits[1].y)
	{
		ymin = line->limits[0].y;
		ymax = line->limits[1].y;
	}
	else
	{
		ymin = line->limits[1].y;
		ymax = line->limits[0].y;
	}
	y = ymin;
	x = line->limits[0].x;
	write = 0;
	while (++y <= ymax)
	{
		ft_color_pixel(mlx, x, y, color);
		write++;
	}
	return (write);
}

void	ft_init_bresenham(t_bresenham *bre, t_line *line)
{
	bre->x[0] = line->limits[0].x;
	bre->x[1] = line->limits[1].x;
	bre->y[0] = line->limits[0].y;
	bre->y[1] = line->limits[1].y;
}

void	ft_bresenham_low(t_mlx *mlx, t_bresenham *bre, int color)
{
	int		y;
	int		x;

	bre->dx = bre->x[1] - bre->x[0];
	bre->dy = bre->y[1] - bre->y[0];
	bre->yi = 1;
	if (bre->dy < 0)
	{
	    bre->yi = -1;
	    bre->dy = -bre->dy;
	}
	bre->d = (2 * bre->dy) - bre->dx;
	y = bre->y[0];

	x = bre->x[0] - 1;
	while (++x <= bre->x[1])
	{
		ft_color_pixel(mlx, x, y, color);
		if (bre->d > 0)
		{
		   y = y + bre->yi;
		   bre->d = bre->d - (2 * bre->dx);
	   	}
		bre->d = bre->d + (2 * bre->dy);
	}
}

void	ft_bresenham_high(t_mlx *mlx, t_bresenham *bre, int color)
{
	int		y;
	int		x;

	bre->dx = bre->x[1] - bre->x[0];
	bre->dy = bre->y[1] - bre->y[0];
	bre->xi = 1;
	if (bre->dx < 0)
	{
	    bre->xi = -1;
	    bre->dx = -bre->dx;
	}
	bre->d = (2 * bre->dx) - bre->dy;
	x = bre->x[0];

	y = bre->y[0] - 1;
	while (++y <= bre->y[1])
	{
		ft_color_pixel(mlx, x, y, color);
		if (bre->d > 0)
		{
		   x = x + bre->xi;
		   bre->d = bre->d - (2 * bre->dy);
	   	}
		bre->d = bre->d + (2 * bre->dx);
	}
}

int		ft_bresenham(t_mlx *mlx, t_line *line, int color)
{
	t_bresenham		bre;

	if (line->limits[0].x == line->limits[1].x)
	{
		ft_xone_equal_xtwo(mlx, line, color);
		return (1);
	}
	ft_init_bresenham(&bre, line);
	if (ft_abs(bre.y[1] - bre.y[0]) < ft_abs(bre.x[1] - bre.x[0]))
	{
		if (bre.x[0] > bre.x[1])
		{
			ft_swap(&bre.x[0], &bre.x[1], sizeof(int));
			ft_swap(&bre.y[0], &bre.y[1], sizeof(int));
		}
		ft_bresenham_low(mlx, &bre, color);
	}
	else
	{
		if (bre.y[0] > bre.y[1])
		{
			ft_swap(&bre.x[0], &bre.x[1], sizeof(int));
			ft_swap(&bre.y[0], &bre.y[1], sizeof(int));
		}
		ft_bresenham_high(mlx, &bre, color);
	}
	return (1);
}
