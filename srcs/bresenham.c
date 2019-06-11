/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:02:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/11 19:12:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

/*
** function line(x0, y0, x1, y1)
** 	real deltax := x1 - x0
** 	real deltay := y1 - y0
** 	real deltaerr := abs(deltay / deltax)    // Assume deltax != 0 (line is not vertical),
** 		  // note that this division needs to be done in a way that preserves the fractional part
** 	real error := 0.0 // No error at start
** 	int y := y0
** 	for x from x0 to x1
** 		plot(x,y)
** 		error := error + deltaerr
** 		if error ≥ 0.5 then
** 			y := y + sign(deltay) * 1
** 			error := error - 1.0
*/

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

void	ft_swap_bresenham(t_line *line)
{
	if (line->limits[0].y > line->limits[1].y
	&& line->limits[0].x > line->limits[1].x) //case bottom-right
		ft_swap(&line->limits[1].x, &line->limits[0].x, sizeof(int));
	else if (line->limits[0].y < line->limits[1].y
	&& line->limits[0].x > line->limits[1].x) //case top-right
	{
		ft_swap(&line->limits[1].x, &line->limits[0].x, sizeof(int));
		// ft_swap(&line->limits[1].x, &line->limits[1].y, sizeof(int));
		// ft_swap(&line->limits[0].x, &line->limits[0].y, sizeof(int));
	}
	else if (line->limits[0].y < line->limits[1].y
	&& line->limits[0].x < line->limits[1].x) //case top-left
	{
		// ft_swap(&line->limits[1].y, &line->limits[0].x, sizeof(int));
		// ft_swap(&line->limits[1].x, &line->limits[0].y, sizeof(int));
		// ft_swap(&line->limits[1].y, &line->limits[0].y, sizeof(int));
		// ft_swap(&line->limits[1].x, &line->limits[0].x, sizeof(int));
	}
	else if (line->limits[0].y > line->limits[1].y
	&& line->limits[0].x < line->limits[1].x) //case bottom-left
	{
	}
}

int		ft_bresenham(t_mlx *mlx, t_line *line, int color)
{
	float	Δx;
	float	Δy;
	int		ymin;
	int		ymax;
	float	Δerr;
	float	err;
	int		y;
	int		x;
	int		write;

	ft_swap_bresenham(line);
	Δx = line->limits[1].x - line->limits[0].x;
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
	Δy = ymax - ymin;
	y = ymin;
	Δy = line->limits[1].y - line->limits[0].y;
	y = line->limits[0].y;
	x = line->limits[0].x;
	write = 0;
	if (Δx)
	{
		Δerr = Δy / Δx;
		err = 0;
		while (x < line->limits[1].x)
		{
			ft_color_pixel(mlx, x, y, color);
			write++;
			err += Δerr;
			while (err >= 0.5)
			{
				y++;
				err--;
			}
			x++;
		}
	}
	else
		ft_xone_equal_xtwo(mlx, line, color);
	return (write);
}
