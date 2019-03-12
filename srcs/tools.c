/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:59:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/12 13:20:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_get_percent(intmax_t x, intmax_t x_max)
{
	return (((float)x / (float)x_max) * 100);
}

/*
** if (percent < ft_get_percent((x * window->height) + y, window->width * window->height))
** {
** 	percent = ft_get_percent((x * window->height) + y, window->width * window->height);
** 	place_cursor(0, 50);
** 	ft_putnbr(percent);
** 	ft_putstr("%   ");
** }
*/
int		ft_window_iter(t_mlx *window, int(*f)(t_mlx *, int, int))
{
	char			percent;
	int				x;
	int				y;

	percent = -1;
	y = -1;
	while (++y < (int)window->height)
	{
		if (percent < ft_get_percent(y, window->height))
		{
			percent++;
			place_cursor(30, 50);
			ft_rgb_color(-1, -1, -1);
			ft_putnbr(percent);
			C_RESET
			ft_putstr("%   \n");
		}
		x = -1;
		while (++x < (int)window->width)
			(*f)(window, x, y);
	}
    return (EXIT_SUCCESS);
}
