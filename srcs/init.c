/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:33:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 04:54:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	ft_check_window_size(t_mlx *window, size_t width, size_t height)
{
	if (!width)
		window->width = SIZE_WIDTH;
	else
		window->width = width;
	if (!height)
		window->height = SIZE_HEIGTH;
	else
		window->height = height;
}

void	*ft_open_window(t_mlx *window, char *title)
{
	if (!title || !*title)
	{
		if ((window->win = mlx_new_window(window->ptr, window->width, window->height, "Fil de Fer")) == NULL)
			return (NULL);
	}
	else
	{
		if ((window->win = mlx_new_window(window->ptr, window->width, window->height, title)) == NULL)
			return (NULL);
	}
	return (window);
}

t_img		*ft_create_img(t_mlx *window, char *title, size_t width, size_t height)
{
	t_img			*img;

	if (!window->img)
		ft_lstadd(&window->img, ft_lstnew_ptr((void*)&img, sizeof(t_img)), 0);
	else
		ft_lstadd_end(window->img, ft_lstnew_ptr((void*)&img, sizeof(t_img)));

	img = ft_lst_reach_end(window->img)->content;

	if (!(img->img = mlx_new_image(window->ptr, window->width, window->height)))
		return (NULL);
	if (!(img->b_img = mlx_new_image(window->ptr, window->width, window->height)))
		return (NULL);

	img->width = width;
	img->height = height;
    img->bits_per_pixel = UNIQ_BPP * 8;
    img->size_line = img->width * UNIQ_BPP;
	img->title = title;
    img->endian = 0;
	img->content_img = (int*)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	img->content_b_img = (int*)mlx_get_data_addr(img->b_img, &img->bits_per_pixel, &img->size_line, &img->endian);
	ft_bzero(img->content_b_img, img->height * img->size_line);
	ft_print_struct_img(img);
	return (img);
}

t_mlx		*ft_init_window(char *title, size_t width, size_t height)
{
	t_mlx			*window;

	window = cnalloc(NULL, sizeof(t_mlx));
	ft_check_window_size(window, width, height);
	if (!(window->ptr = mlx_init()))
		return (NULL);
	if (!ft_open_window(window, title))
		return (NULL);
	ft_print_struct_mlx(window);
	if (!(ft_create_img(window, "GLOBAL", window->width, window->height)))
		return (NULL);
	ft_print_struct_mlx(window);
	return (window);
}
