/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:37:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 18:58:51 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_display_swag(t_mlx *window, int x, int y)
{
	int		color;
	t_list	*lst;
	t_img	*img;

	lst = ft_lst_reach_end(window->img);
	img = lst->content;
	color = ft_nice_view(window->choice, (img->height * y), x);
	//ft_bzero(&color, 1);
	//return(mlx_pixel_put(window->ptr, window->win, x, y, color));
	img->content_img[(img->height * x) + y] = color;
	return (color);
}
