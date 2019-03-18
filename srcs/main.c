/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 00:47:36 by ldevelle         ###   ########.fr       */
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
	t_line			*line;
	int				y;
	int				x;

	if (ac < 2 && ac > 4)
		return (0);
	//fd = open(argv[1], O_RDONLY);
	if (!(window = ft_init_window(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();

	x = SIZE_WIDTH;
	y = SIZE_HEIGTH - TRANS;
	img = window->img->content;
	window->choice = 3;
	CURSOR_SAVE
	// while (++window->choice < 4)
	{
		ft_putstr("Start generating choice n*");
		ft_putnbr(window->choice);
		ft_putendl("");
		// ft_window_iter(window, &ft_display_swag);
		//mlx_put_image_to_window(window->ptr, window->win, img->b_img, 0, 0);
		//ft_putstr("Clean screen\n");
		mlx_clear_window(window->ptr, window->win);
		line = ft_line(ft_get_point(0, 0), ft_get_point(x, y));
		ft_line_gradient(window, line);
		line = ft_line(ft_get_point(0, TRANS), ft_get_point(x, y + TRANS));
		ft_draw_line(window, line, 0x00ffffff);
		mlx_put_image_to_window(window->ptr, window->win, img->img, 0, 0);
		CURSOR_LOAD
		ft_putstr("New image appplied              \n");
		// ft_wait_pls(0);
		// ft_wait_pls(0);
		// ft_wait_pls(0);
		// ft_wait_pls(0);
		// ft_wait_pls(0);
		CURSOR_SAVE
	}
	// ft_putendl("");
	// while (window->width--)
	// {
	// 	place_cursor(50, 0);
	// 	ft_putstr_color("END OF FREE WILL", -1, -1 , -1);
	// 	ft_wait_pls(500000);
	// }
	mlx_loop(window->ptr);
	ft_clean_fdf(window);
	return (0);
}
