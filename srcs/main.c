/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 16:43:21 by amartino         ###   ########.fr       */
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
	if (button == 1)
	{
		ft_color_pixel((param), x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *param)
{
	if (button == 1)
	{
		ft_color_pixel((param), x, y, 0x00ffffff);
		render(param);
		return (1);
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
	mlx_hook(mlx->window_pointer, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->window_pointer, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->window_pointer, 2, 0, mouse_release, mlx);
	mlx_loop(mlx->mlx_pointer);
	ft_clean_fdf(mlx);
	return (0);
}
