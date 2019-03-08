/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 05:48:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"


void *mlx_new_image ( void *mlx_ptr, int width, int height );

int mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );

int mlx_destroy_image ( void *mlx_ptr, void *img_ptr );

char *mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );

unsigned int mlx_get_color_value ( void *mlx_ptr, int color );

int		main(int ac, char **av)
{
	t_mlx			*window;
	t_img			*img;

	if (ac < 2 && ac > 4)
		return (0);
	//fd = open(argv[1], O_RDONLY);
	if (!(window = ft_init_window(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();



	ft_window_iter(window, &ft_display_swag);
	img = window->img->content;
	mlx_put_image_to_window(window->ptr, window->win, img->img, 0, 0);

	mlx_loop(window->ptr);
	ft_clean_fdf(window);
	return (0);
}
