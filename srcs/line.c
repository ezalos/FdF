/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:08:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/12 15:34:07 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

t_point		*ft_get_point(int x, int y)
{
	t_point		*point;

	if (!(point = ft_memalloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

t_line		*ft_line(t_point *one, t_point *two)
{
	t_line		*line;

	if (!(line = ft_memalloc(sizeof(t_line))))
		return (NULL);
	line->a = (double)(two->y - one->y) / (double)(two->x - one->x);
	line->b = (double)one->y - (line->a * (double)one->x);
	line->limits[0] = *one;
	line->limits[1] = *two;
	return (line);
}

double		ft_f_of_x(t_line *line, double x)
{
	return ((line->a * x) + line->b);
}

double		ft_get_decimal(double number)
{
	return (number - (int)number); //double - int ?
}

int			ft_get_per_ntenth(double number, char precision)
{
	return ((int)((double)ft_power(10, (int)precision) * number));
}

t_img		ft_line_gradient(t_img *img, t_line *line)
{
	int		bound;
	int		x_start;

	x_start = line->limits[0].x;
	while (x_start < line->limits[1].x)
	{
		bound = ft_get_per_ntenth(ft_get_decimal(ft_line_point(line, x_start)), 3)

	}
}
