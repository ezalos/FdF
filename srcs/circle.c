/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:11:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/13 19:19:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"
#include <math.h>

int		ft_draw_circle(t_mlx *mlx, int x, int y, int radius)
{
	t_point		*center;
	t_point		*point;
	int			x_;
	int			y_;

	center = ft_get_point(x, y);
	x_ = x + radius;
	y_ = y;
	// ft_printf("%s\n", __func__);
	while (y_ < y + radius)
	{
		point = ft_get_point(x_, y_);
		ft_bresenham(mlx, ft_line(center, point), ft_get_color(0, 255, 0, 0));
		x_--;
		y_++;
	}
	while (y_ > y)
	{
		point = ft_get_point(x_, y_);
		ft_bresenham(mlx, ft_line(center, point), ft_get_color(0, 0, 255, 0));
		x_--;
		y_--;
	}
	while (y_ > y - radius)
	{
		point = ft_get_point(x_, y_);
		ft_bresenham(mlx, ft_line(center, point), ft_get_color(0, 0, 0, 255));
		x_++;
		y_--;
	}
	while (x_ < x + radius)
	{
		point = ft_get_point(x_, y_);
		ft_bresenham(mlx, ft_line(center, point), ft_get_color(0, 255, 255, 0));
		x_++;
		y_++;
	}
	// ft_printf("%llU\n", ft_get_color(0, 255, 0, 0));
	render(mlx);
	return (1);
}

void 		ft_draw_a_circle (t_mlx *mlx, int x, int y, int radius, unsigned int color)
{
	t_point		*center;
	t_point		*point;
    int length = radius;
	int x_, y_;
    float angle = 0.0;
    float angle_stepsize = 1 / (2 * M_PI * radius);

    // go through all angles from 0 to 2 * PI radians
	center = ft_get_point(x, y);
    while (angle < 2 * M_PI)
    {
        // calculate x, y from a vector with known length and angle
        x_ = length * cos (angle);
        y_ = length * sin (angle);
		point = ft_get_point(x + x_, y + y_);
		ft_bresenham(mlx, ft_line(center, point), color);
        angle += angle_stepsize;
  }
  render(mlx);
}
