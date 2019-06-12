/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:19:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/12 02:21:48 by ldevelle         ###   ########.fr       */
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

unsigned int		ft_get_color_pixel(t_mlx *mlx, int x, int y)
{
	t_list			*lst;
	t_img			*img;
	unsigned int	color;

	if (x < 0 || x >= (int)mlx->width)
		return (-1);
	if (y < 0 || y >= (int)mlx->height)
		return (-1);
	lst = ft_lst_reach_end(mlx->image_list);
	img = lst->content;
	color = img->my_image_data[(img->width * y) + x];
	return (color);
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

int		ft_ponderate_mean(int x, int y, float mult)
{
	int sav;

	sav = ((float)x * mult) + y;
	return (sav > 255 ? 255 : sav);
	return ((int)(((float)x * (mult)) + ((float)y * (1 - mult))));
}

int		ft_get_primary_color(int color, char nb)
{
	/*
	** 	blue: nb = 0
	** 	green: nb = 1
	** 	red: nb = 2
	** 	brightness: nb = 3
	*/
	// if (nb == 0)
	// 	ft_printf("blue: ");
	// else if (nb == 1)
	// 	ft_printf("green: ");
	// else if (nb == 2)
	// 	ft_printf("red: ");
	// else if (nb == 3)
	// 	ft_printf("alpha: ");
	unsigned char	*color_str;

	color_str = (unsigned char*)&color;
	// ft_printf("%d\n", (int)color_str[(int)nb]);
	return ((int)color_str[(int)nb]);

}

int		ft_add_color_pixel(t_mlx *mlx, int x, int y, unsigned int new_color, float brightness)
{
	unsigned int	old_color;
	unsigned int	mix_color;
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;

	// brightness = 1;
	old_color = ft_get_color_pixel(mlx, x, y);
	// ft_printf("old color: %d\n", old_color);
	mix_color = 0;
	red = ft_ponderate_mean(ft_get_primary_color(new_color, 2),
		ft_get_primary_color(old_color, 2), brightness);
	green = ft_ponderate_mean(ft_get_primary_color(new_color, 1),
		ft_get_primary_color(old_color, 1), brightness);
	blue = ft_ponderate_mean(ft_get_primary_color(new_color, 0),
		ft_get_primary_color(old_color, 0), brightness);
	mix_color = ft_get_color(0, red, green, blue);

	// ft_printf("%d\tR%dG%dB%d\n", brightness, red, green, blue);
	ft_color_pixel(mlx, x, y, mix_color);
	return (mix_color);
}
