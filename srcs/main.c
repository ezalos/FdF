/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/11 17:58:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int ft_hook(int x_event, int x_mask)
{
	ft_printf("Mlx Hook:\n\tx_event: %d\n\tx_mask: %d\n", x_event, x_mask);
	return (1);
}

int			mouse_press(int button, int x, int y, t_mlx *param)
{
	t_list			*lst;
	t_img			*img;
	t_mlx			*mlx;
	t_line 			*line;
	t_point 		*actual;
	static t_point 	*last;

	ft_printf("Mouse press\n\tbutton: %d\n\tx: %d\n\ty: %d\n", button, x, y);
	if (button == 1)
	{
		ft_color_pixel((param), x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	else if (button == 2)
	{
		mlx = param;
		lst = ft_lst_reach_end(((t_mlx*)mlx)->image_list);
		img = lst->content;
		actual = ft_get_point(x, y);
		if (actual && last)
		{
			line = ft_line(last, actual);
			ft_line_gradient(mlx, line);
			render(mlx);
		}
		else
			img->my_image_data[(img->width * y) + x] = 0x00ffffff;
		last = actual;
		return (0);
	}
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *param)
{
	// t_list			*lst;
	// t_img			*img;
	// t_mlx			*mlx;
	// t_line 			*line;
	// t_point 		*actual;
	// static t_point 	*last;

	ft_printf("Mouse release\n\tbutton: %d\n\tx: %d\n\ty: %d\n", button, x, y);
	if (button == 1)
	{
		ft_color_pixel((param), x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	else if (button == 2)
	{
		// mlx = param;
		// lst = ft_lst_reach_end(((t_mlx*)mlx)->image_list);
		// img = lst->content;
		// actual = ft_get_point(x, y);
		// if (actual && last)
		// {
		// 	line = ft_line(last, actual);
		// 	ft_line_gradient(mlx, line);
		// 	render(mlx);
		// }
		// else
		// 	img->my_image_data[(img->width * y) + x] = 0x00ffffff;
		// last = actual;
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx			*mlx;

	if (ac < 2 && ac > 4)
		return (0);
	if (!(mlx = ft_init_mlx(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();
	// ft_bresenham(mlx, ft_line(ft_get_point(100, 0), ft_get_point(100, 100)));
	// render(mlx);
	ft_draw_circle(mlx, mlx->width / 2, mlx->height / 2, 500);
	mlx_hook(mlx->window_pointer, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->window_pointer, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->window_pointer, 2, 0, mouse_release, mlx);
	mlx_loop(mlx->mlx_pointer);
	ft_clean_fdf(mlx);
	return (0);
}
