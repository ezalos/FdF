/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2020/08/08 16:53:34 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		parsing_fractol(int ac, char **av)
{
	parse_new("fractol", "display a swaggy fractal");

	parse_add_option('M', "Mandelbrot",	"Display Mandelbrot Fractal");
	parse_add_option('o', "Movement",	"Julia movement Fractal");
	parse_add_option('J', "Julia",	"Display Julia ensemble Fractal");
	if (parse_args(ac, av) == FAILURE)
		return (FAILURE);
	if (parse_get("help") != NULL)
	{
		parse_usage();
		return (FAILURE);
	}
	return (SUCCESS);
}

// #include <libcpuid.h>

int		main(int ac, char **av)
{
	t_mlx			*mlx;
    // struct cpu_raw_data_t raw;
    // struct cpu_id_t data;
	//
    // cpuid_get_raw_data(&raw);
    // cpu_identify(&raw, &data);
    // printf("No. of Physical Core(s) : %d\n", data.num_cores);

	if (parsing_fractol(ac, av) == FAILURE)
		return (FAILURE);
	if (!(mlx = ft_init_mlx(av[0], ft_atoi(av[2]), ft_atoi(av[3]))))
		ft_clean_garbage();
//	set_up_palettes(mlx);
	set_up_palettes(&mlx->fractal.colors);
	thread_fractol(mlx, NB_THREAD);
	render(mlx);
	mlx_hooks_and_loop(mlx);
	return (0);
}
