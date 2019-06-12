/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/12 18:21:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int ft_hook(int x_event, int x_mask)
{
	ft_printf("Mlx Hook:\n\tx_event: %d\n\tx_mask: %d\n", x_event, x_mask);
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx			*mlx;
	int				color;

	if (ac < 2 && ac > 4)
		return (0);
	if (!(mlx = ft_init_mlx(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();
	ft_printf("My own\n");
	if (parsing(av[1], mlx) == 0)
		ft_clean_garbage();
	color = ft_get_color(0, 0, 0, 0);
	// ft_printf("FIRST color: %d\n", color);
	// ft_color_pixel(mlx, 100, 100, color);
	// color = ft_get_color(0, 50, 100, 200);
	// ft_printf("SECOND color: %d\n", color);
	// ft_add_color_pixel(mlx, 100, 100, color, 0.5);
	// ft_bresenham(mlx, ft_line(ft_get_point(100, 0), ft_get_point(100, 100)));
	// render(mlx);
	ft_draw_circle(mlx, mlx->width / 2, mlx->height / 2, 500);
	mlx_hook(mlx->window_pointer, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->window_pointer, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->window_pointer, 2, 0, mouse_release, mlx);
	mlx_loop(mlx->mlx_pointer);
	// ft_clean_fdf(mlx);
	// render(mlx);
	// mlx_hook(mlx->window_pointer, 2, 0, key_press, mlx);
	// mlx_hook(mlx->window_pointer, 3, 0, key_release, mlx);
	// mlx_hook(mlx->window_pointer, 4, 0, mouse_press, mlx);
	// mlx_hook(mlx->window_pointer, 5, 0, mouse_release, mlx);
	// mlx_hook(mlx->window_pointer, 6, 0, mouse_move, mlx);
	// mlx_loop(mlx->mlx_pointer);
	return (0);
}
