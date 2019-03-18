/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:50:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 00:43:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

unsigned int		ft_get_color(unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned int				color;
	unsigned char	bad_col[4];
	//char			*str;

	bad_col[3] = alpha;
	bad_col[2] = red;
	bad_col[1] = green;
	bad_col[0] = blue;
	ft_memmove(&color, bad_col, 4);
	// printf("string\tchar recpt\tint fin\n");
	//str = ft_nb_to_a(color, 16);
	// printf("%d\t%d\t\t%s\n", bad_col[0], alpha, str);
	// printf("%d\t%d\t\t%d\n", bad_col[1], red, (int)((unsigned char*)&color)[1]);
	// printf("%d\t%d\t\t%d\n", bad_col[2], green, (int)((unsigned char*)&color)[2]);
	// printf("%d\t%d\t\t%d\n", bad_col[3], blue, (int)((unsigned char*)&color)[3]);
	return (color);
}
