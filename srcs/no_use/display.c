/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:37:44 by ldevelle          #+#    #+#             */
/*   Updated: 2020/06/30 18:47:08 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_color_pixel_swag(t_mlx *mlx, int x, int y)
{
	int		color;
	t_list	*lst;
	t_img	*img;

	lst = ft_lst_reach_end(mlx->image_list);
	img = lst->content;
	color = ft_nice_view(mlx->choice, x, y);
	img->my_image_data[(img->width * y) + x] = 0x00ffffff;
	return (color);
}
