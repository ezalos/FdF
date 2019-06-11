/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/11 15:28:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		main(int ac, char **av)
{
	t_mlx			*mlx;

	if (ac < 2 && ac > 4)
		return (0);
	if (!(mlx = ft_init_mlx(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();
	ft_printf("My own\n");
	if (parsing(av[1], mlx) == 0)
		ft_clean_garbage();
	// render(mlx);
	// mlx_hook(mlx->window_pointer, 2, 0, key_press, mlx);
	// mlx_hook(mlx->window_pointer, 3, 0, key_release, mlx);
	// mlx_hook(mlx->window_pointer, 4, 0, mouse_press, mlx);
	// mlx_hook(mlx->window_pointer, 5, 0, mouse_release, mlx);
	// mlx_hook(mlx->window_pointer, 6, 0, mouse_move, mlx);
	// mlx_loop(mlx->mlx_pointer);
	return (0);
}
