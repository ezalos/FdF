/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easter_egg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/12 13:27:28 by ldevelle         ###   ########.fr       */
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

int	ft_nice_view(int choice, int x, int y)
{
	if (choice == 0)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 1)
		return (ft_random(-2147483648, 2147483647, ((x + 1) / (y + 1)) + 1, 1));
	else if (choice == 2)
		return (ft_random(-2147483648, 2147483647, y + x + 1, 1));
	else if (choice == 3)
		return (ft_random(-2147483648, 2147483647, (y % (x + 1)) + 1, 1));
	else if (choice == 4)
		return (ft_random(-2147483648, 2147483647, ((y * y) + 1 / ((x * x) + 1)) + 1, 1));
	else if (choice == 5)
		return (ft_random(-2147483648, 2147483647, ((y * y) + (x * x)) /(1 + ((x + y) * (x + y))), 1));
	else if (choice == 6)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 7)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 8)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 9)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 10)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else
		return (0);
}
