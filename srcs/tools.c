/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:59:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 01:00:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_window_iter(t_mlx *window, int(*f)(t_mlx *, int, int))
{
	int				x;
	int				y;

	x = -1;
	while (++x < (int)window->width)
	{
		y = -1;
		while (++y < (int)window->height)
			(*f)(window, x, y);
	}
    return (EXIT_SUCCESS);
}
