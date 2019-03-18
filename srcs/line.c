/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:08:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 00:47:15 by ldevelle         ###   ########.fr       */
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
	return ((int)((double)ft_power(10, (int)precision) * (number)));
}

int			ft_get_bound(double number)
{
	return (ft_get_per_ntenth(ft_get_decimal(number) - 0.5, PRECISION));
}

int		ft_display_if_brighter(t_mlx *window, int x, int y, int color)
{
	t_list	*lst;
	t_img	*img;

	lst = ft_lst_reach_end(window->img);
	img = lst->content;
	if (img->content_img[(img->width * y) + x] < color)
	{
		img->content_img[(img->width * y) + x] = color;
		return (color);
	}
	return (-1);
}

int		ft_display(t_mlx *window, int x, int y, int color)
{
	t_list	*lst;
	t_img	*img;

	lst = ft_lst_reach_end(window->img);
	img = lst->content;
	img->content_img[(img->width * y) + x] = color;
	return (color);
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

int		ft_draw_line(t_mlx *window, t_line *line, int color)
{
	int		x;
	int		y;

	x = line->limits[0].x - 1;
	while (++x < line->limits[1].x)
	{
		y = ft_f_of_x(line, x);
		ft_display(window, x, y, color);
	}
	return (line->limits[0].x - x);
}

int		ft_how_far(double y, double x)
{


	return (ft_fsqrt(ft_power(x, 2) + ft_power(y, 2), 0));
	return (ft_power(x, 2) + ft_power(y, 2));
}

/*
** ft_display_if_brighter(window, x, y, ft_get_grey(bound_x, PRECISION, 0));
*/

int		ft_line_gradient(t_mlx *window, t_line *line)
{
	int			bound_x;
	int			bound_y;
	double		x;
	double		y;

	x = line->limits[0].x;
	while (x < line->limits[1].x)
	{
		y = ft_f_of_x(line, x);
		if (y + 1 >= window->height)
			return (0);
		bound_y = ft_get_bound(y);
		bound_x = ft_get_bound(x);
		ft_display_if_brighter(window, x, y, ft_get_grey(ft_how_far(bound_y, bound_x), PRECISION));
		x += 0.001;
	}
	return (line->limits[0].x - x);
}
