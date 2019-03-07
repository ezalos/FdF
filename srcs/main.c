/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/07 20:12:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

/*
** void *
** mlx_new_image ( void *mlx_ptr, int width, int height );
**
** char *
** mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
**
** int
** mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
**
** unsigned int
** mlx_get_color_value ( void *mlx_ptr, int color );
**
** void *
** mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );
**
** void *
** mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
**
** int
** mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
**
**        int
**        mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color);
**
**        int
**        mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
*/



int main_dos(int x, int y)
{
	int				color;
	unsigned char	bad_col[4];
    data_t			data;

	bad_col[0] = 0;
	bad_col[1] = ft_random(0, 255, 0, 0);
	bad_col[2] = ft_random(0, 255, 0, 0);
	bad_col[3] = ft_random(0, 255, 0, 0);
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, SIZE_WIDTH, SIZE_HEIGTH, "Hello world")) == NULL)
        return (EXIT_FAILURE);
	x = -1;
	ft_memmove(&color, bad_col, 4);
	printf("%d\n-%d\n0255255255\n", color, 0255255255);
	while (++x < SIZE_WIDTH)
	{
		y = -1;
		while (++y < SIZE_HEIGTH)
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, ft_random(-2147483648, 2147483647, x + 1, y + 1));
	}
	mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	if (!ac)
		return (0);
	(void)av;
	main_dos(ft_atoi(av[1]), ft_atoi(av[2]));
	return (0);
}
