/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:11:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/11 23:14:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_draw_circle(t_mlx *mlx, int x, int y, int radius)
{
	t_point		*center;
	t_point		*point;
	int			x_;
	int			y_;

	center = ft_get_point(x, y);
	x_ = x + radius;
	y_ = y;
	ft_printf("%s\n", __func__);
	while (y_ < y + radius)
	{
		point = ft_get_point(x_, y_);
		if (!(y_ % 10) && !(x_ % 10))
			ft_printf("%~{255;0;0}1\tx: %d/%d\ty: %d/%d\n", x_, x, y_, y);
		ft_xiaolin_wu(mlx, ft_line(center, point), ft_get_color(0, 255, 0, 0));
		x_--;
		y_++;
	}
	while (y_ > y)
	{
		point = ft_get_point(x_, y_);
		if (!(y_ % 10) && !(x_ % 10))
			ft_printf("%~{0;255;0}2\tx: %d/%d\ty: %d/%d\n", x_, x, y_, y);
		ft_xiaolin_wu(mlx, ft_line(center, point), ft_get_color(0, 0, 255, 0));
		x_--;
		y_--;
	}
	while (y_ > y - radius)
	{
		point = ft_get_point(x_, y_);
		if (!(y_ % 10) && !(x_ % 10))
			ft_printf("%~{0;0;255}3\tx: %d/%d\ty: %d/%d\n", x_, x, y_, y);
		ft_xiaolin_wu(mlx, ft_line(center, point), ft_get_color(0, 0, 0, 255));
		x_++;
		y_--;
	}
	while (x_ < x + radius)
	{
		point = ft_get_point(x_, y_);
		if (!(y_ % 10) && !(x_ % 10))
			ft_printf("%~{255;255;0}4\tx: %d/%d\ty: %d/%d\n", x_, x, y_, y);
		ft_xiaolin_wu(mlx, ft_line(center, point), ft_get_color(0, 255, 255, 0));
		x_++;
		y_++;
	}
	ft_printf("%llU\n", ft_get_color(0, 255, 0, 0));
	render(mlx);
	return (1);
}
