/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:33:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 19:28:14 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	ft_check_window_size(t_mlx *mlx, size_t width, size_t height)
{
	if (!width)
		mlx->width = SIZE_WIDTH;
	else
		mlx->width = width;
	if (!height)
		mlx->height = SIZE_HEIGTH;
	else
		mlx->height = height;
}

void	*ft_open_mlx(t_mlx *mlx, char *title)
{
	if (!title || !*title)
	{
		if ((mlx->window_pointer = mlx_new_window(mlx->mlx_pointer, mlx->width, mlx->height, "Fil de Fer")) == NULL)
			return (NULL);
	}
	else
	{
		if ((mlx->window_pointer = mlx_new_window(mlx->mlx_pointer, mlx->width, mlx->height, title)) == NULL)
			return (NULL);
	}
	return (mlx);
}

t_img		*ft_create_img(t_mlx *mlx, char *title, size_t width, size_t height)
{
	t_img			*img;

	if (!mlx->image_list)
		ft_lstadd(&mlx->image_list, ft_lstnew_ptr((void*)&img, sizeof(t_img)), 0);
	else
		ft_lstadd_end(mlx->image_list, ft_lstnew_ptr((void*)&img, sizeof(t_img)));

	img = ft_lst_reach_end(mlx->image_list)->content;

	if (!(img->image_pointer = mlx_new_image(mlx->mlx_pointer, mlx->width, mlx->height)))
		return (NULL);
	img->width = width;
	img->height = height;
	img->title = title;
	img->my_image_data = (int*)mlx_get_data_addr(img->image_pointer, &img->bits_per_pixel, &img->size_line, &img->endian);
	ft_print_struct_img(img);
	return (img);
}

t_mlx		*ft_init_mlx(char *title, size_t width, size_t height)
{
	t_mlx			*mlx;

	mlx = cnalloc(NULL, sizeof(t_mlx));
	ft_check_window_size(mlx, width, height);
	if (!(mlx->mlx_pointer = mlx_init()))
		return (NULL);
	if (!ft_open_mlx(mlx, title))
		return (NULL);
	ft_print_struct_mlx(mlx);
	if (!(ft_create_img(mlx, "GLOBAL", mlx->width, mlx->height)))
		return (NULL);
	ft_print_struct_mlx(mlx);
	return (mlx);
}
