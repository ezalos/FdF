/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easter_egg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/12 18:55:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int	ft_nice_view(int choice, int x, int y)
{
	if (choice == 0)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 1)
		return (ft_random(-2147483648, 2147483647, ((x + 1) / (y + 1)) + 1, 1));
	else if (choice == 2)
		return (ft_random(-2147483648, 2147483647, y + x + 1, 1));
	else if (choice == 3)
		return (ft_random(-2147483648, 2147483647, (y % (x + 1)) + 1, 1));
	else if (choice == 4)
		return (ft_random(-2147483648, 2147483647, ((y * y) + 1 / ((x * x) + 1)) + 1, 1));
	else if (choice == 5)
		return (ft_random(-2147483648, 2147483647, ((y * y) + (x * x)) /(1 + ((x + y) * (x + y))), 1));
	else if (choice == 6)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 7)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 8)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 9)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 10)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else
		return (0);
}

int			draw_lines_dynamically(int x, int y, t_mlx *param)
{
	t_list			*lst;
	t_img			*img;
	t_mlx			*mlx;
	t_line 			*line;
	t_point 		*actual;
	static t_point 	*last;

	mlx = param;
	lst = ft_lst_reach_end(mlx->image_list);
	img = lst->content;
	actual = ft_get_point(x, y);
	if (actual && last)
	{
		line = ft_line(last, actual);
		ft_xiaolin_wu(mlx, line, ft_get_color(0, ft_random(0, 0, 0, 0), ft_random(0, 0, 0, 0), ft_random(0, 0, 0, 0)));
		render(mlx);
	}
	else
		img->my_image_data[(img->width * y) + x] = 0x00ffffff;
	last = actual;
	return (0);
}
