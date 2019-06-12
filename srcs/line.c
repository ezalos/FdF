/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:08:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/12 18:22:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

t_line		*ft_line(t_point *one, t_point *two)
{
	t_line		*line;

	if (!(line = ft_memalloc(sizeof(t_line))))
		return (NULL);
	if (!(two->x - one->x))
	{
		line->a = NAN;
		line->b = NAN;
		if (one->x > two->x)
		{
			line->limits[0] = *two;
			line->limits[1] = *one;
		}
		else
		{
			line->limits[0] = *one;
			line->limits[1] = *two;
		}
	}
	else if (one->x > two->x)
	{
		line->a = (double)(one->y - two->y) / (double)(one->x - two->x);
		line->b = (double)two->y - (line->a * (double)two->x);
		line->limits[0] = *two;
		line->limits[1] = *one;
	}
	else
	{
		line->a = (double)(two->y - one->y) / (double)(two->x - one->x);
		line->b = (double)one->y - (line->a * (double)one->x);
		line->limits[0] = *one;
		line->limits[1] = *two;
	}
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
	return ((int)((double)ft_power(10, (int)precision) * (number)));
}

int			ft_get_bound(double number)
{
	return (ft_get_per_ntenth(ft_get_decimal(number) - 0.5, PRECISION));
}

//127-150
//si grey > 127 aucun pixel ne s'affiche. Pourtant ft_get_color fonctionne parfaitement
int		ft_get_grey(int per_nth, char precision)
{
	unsigned char		grey;
	double				percent;

	per_nth = (double) per_nth / (1.75);
	percent = ((double) per_nth / ((double)ft_power(10, (int)precision)));
	grey = 255.0 * (1.0 - percent);
	// if (grey > 250)
	// printf("%d|", grey);
	return (ft_get_color(0, grey, grey, grey)); //play only with the alpha parameter to obtaincolor's gradient
}

int		ft_draw_line(t_mlx *mlx, t_line *line, int color)
{
	int		x;
	int		y;

	x = line->limits[0].x - 1;
	while (++x < line->limits[1].x)
	{
		y = ft_f_of_x(line, x);
		ft_color_pixel(mlx, x, y, color);
	}
	return (line->limits[0].x - x);
}

int		ft_how_far(double y, double x)
{


	return (ft_fsqrt(ft_power(x, 2) + ft_power(y, 2), 0));
	return (ft_power(x, 2) + ft_power(y, 2));
}

int		ft_line_gradient(t_mlx *mlx, t_line *line)
{
	// int			bound_x;
	// int			bound_y;
	double		x;
	double		y;
	double		step;

	// ft_printf("%s\n", __func__);
	if (!(line->a != line->a))
	{
		// ft_printf("%s\n", "normal");
		step = 1 / line->a;
		step /= 2;
		x = line->limits[0].x;
		y = 0;
		while (x < line->limits[1].x && y <= mlx->height && y >= 0)
		{
			y = ft_f_of_x(line, x);
			// bound_y = ft_get_bound(y);
			// bound_x = ft_get_bound(x);
			ft_color_pixel(mlx, x, y, 0x00ffffff);
			// ft_color_pixel_if_brighter(mlx, x, y, ft_get_grey(ft_how_far(bound_y, bound_x), PRECISION));
			x += step;
		}
	}
	else
	{
		step = 1;
		ft_printf("%s\n", "vertical");
		(void)x;
		y = line->limits[0].y;
		while (y < line->limits[1].y)
		{
			ft_color_pixel(mlx, line->limits[1].x, y, 0x00ffffff);
			y += step;
		}

	}
	return (1);
}


int		ft_my_line(t_mlx *mlx, t_line *line, int color)
{
	double		x;
	double		y;
	double		step;

	step = 1;
	if (!(line->a != line->a))
	{
		if (line->a)
			step /= line->a;
		if (step < 0)
			step = -step;
		// step /=1000;
		x = line->limits[0].x;
		y = 0;
		while (x <= line->limits[1].x)
		{
			// if (color == PX_WHITE)
			// ft_printf("f(%f)=%f\n", x, y);
			y = ft_f_of_x(line, x);
			ft_color_pixel(mlx, x, y, color);
			x += step;
		}
	}
	else
	{
		y = line->limits[0].y;
		while (y <= line->limits[1].y)
		{
			ft_color_pixel(mlx, line->limits[1].x, y, color);
			y += step;
		}
	}
	return (1);
}
