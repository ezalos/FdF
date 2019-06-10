/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:59:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 16:44:42 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_get_percent(intmax_t x, intmax_t x_max)
{
	return (((float)x / (float)x_max) * 100);
}

int		ft_mlx_iter(t_mlx *mlx, int(*f)(t_mlx *, int, int))
{
	char			percent;
	int				x;
	int				y;

	percent = -1;
	y = -1;
	while (++y < (int)mlx->height)
	{
		if (percent < ft_get_percent(y, mlx->height))
		{
			percent++;
			ft_place_cursor(30, 50);
			ft_rgb_color(-1, -1, -1);
			ft_putnbr(percent);
			C_RESET
			ft_putstr("%   \n");
		}
		x = -1;
		while (++x < (int)mlx->width)
			(*f)(mlx, x, y);
	}
    return (EXIT_SUCCESS);
}
