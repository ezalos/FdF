/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:19:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/11 19:09:25 by ldevelle         ###   ########.fr       */
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

int		ft_color_pixel_if_brighter(t_mlx *mlx, int x, int y, int color)
{
	t_list	*lst;
	t_img	*img;

	lst = ft_lst_reach_end(mlx->image_list);
	img = lst->content;
	if (x < 0 || x > (int)mlx->width)
		return (-1);
	if (y < 0 || y > (int)mlx->height)
		return (-1);
	if (img->my_image_data[(img->width * y) + x] < color)
	{
		img->my_image_data[(img->width * y) + x] = color;
		return (color);
	}
	return (-1);
}

int		ft_color_pixel(t_mlx *mlx, int x, int y, int color)
{
	t_list	*lst;
	t_img	*img;

	if (x < 0 || x >= (int)mlx->width)
		return (-1);
	if (y < 0 || y >= (int)mlx->height)
		return (-1);
	lst = ft_lst_reach_end(mlx->image_list);
	img = lst->content;
	img->my_image_data[(img->width * y) + x] = color;
	return (color);
}
