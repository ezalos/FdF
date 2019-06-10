/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 01:48:03 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 16:48:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void		ft_print_struct_img(t_img *mlx)
{
	ft_putstr("\n~~~~~");
	C_YELLOW
	ft_putstr(__func__);
	C_RESET
	ft_putstr("~~~~~\n");
	//CURSOR_RESET
	ft_putstr("WINDOW:\t\t");
	ft_print_address_color((intmax_t)mlx);
	ft_putendl("");
	ft_putstr("img:\t\t");
	ft_print_address_color((intmax_t)mlx->image_pointer);
	ft_putstr("\twidth:\t");
	C_CYAN
	ft_putnbr(mlx->width);
	C_RESET
	ft_putendl("");
	ft_putstr("\theight:\t");
	C_RED
	ft_putnbr(mlx->height);
	C_RESET
	ft_putendl("");
	ft_putstr("my_image_data:\t");
	ft_print_address_color((intmax_t)mlx->my_image_data);
	ft_putendl("");
	ft_putendl("");
	ft_putstr("\t\t\t\tbits per px:\t");
	C_RED
	ft_putnbr(mlx->bits_per_pixel);
	C_RESET
	ft_putendl("");
	ft_putstr("\t\t\t\tsize_line:\t");
	C_RED
	ft_putnbr(mlx->size_line);
	C_RESET
	ft_putendl("");
	ft_putstr("\t\t\t\tendian:\t\t");
	C_RED
	ft_putnbr(mlx->endian);
	C_RESET
	ft_putstr("\n");
	ft_putstr("\n");

}
void		ft_print_struct_mlx(t_mlx *mlx)
{
	ft_putstr("\n~~~~~");
	C_YELLOW
	ft_putstr(__func__);
	C_RESET
	ft_putstr("~~~~~\n");
	//CURSOR_RESET
	ft_putstr("WINDOW:\t");
	ft_print_address_color((intmax_t)mlx);
	ft_putendl("");
	ft_putstr(":\t");
	ft_print_address_color((intmax_t)mlx->mlx_pointer);
	ft_putstr("\twidth:\t");
	C_CYAN
	ft_putnbr(mlx->width);
	C_RESET
	ft_putendl("");
	ft_putstr("win:\t");
	ft_print_address_color((intmax_t)mlx->window_pointer);
	ft_putstr("\theight:\t");
	C_RED
	ft_putnbr(mlx->height);
	C_RESET
	ft_putendl("");
	ft_putstr("img:\t");
	ft_print_address_color((intmax_t)mlx->image_list);
	ft_putendl("");
	ft_putstr("\n");
}
