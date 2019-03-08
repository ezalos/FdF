/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:50:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 00:51:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_get_color(unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue)
{
	int				color;
	unsigned char	bad_col[4];

	bad_col[0] = alpha;
	bad_col[1] = red;
	bad_col[2] = green;
	bad_col[3] = blue;
	ft_memmove(&color, bad_col, 6);
	return (color);
}
