/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 01:48:03 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 04:52:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void		ft_print_struct_img(t_img *window)
{
	ft_putstr("\n~~~~~");
	C_YELLOW
	ft_putstr(__func__);
	C_RESET
	ft_putstr("~~~~~\n");
	//CURSOR_RESET
	ft_putstr("WINDOW:\t\t");
	ft_print_address_color((intmax_t)window);
	ft_putendl("");
	ft_putstr("img:\t\t");
	ft_print_address_color((intmax_t)window->img);
	ft_putstr("\twidth:\t");
	C_CYAN
	ft_putnbr(window->width);
	C_RESET
	ft_putendl("");
	ft_putstr("b_img:\t\t");
	ft_print_address_color((intmax_t)window->b_img);
	ft_putstr("\theight:\t");
	C_RED
	ft_putnbr(window->height);
	C_RESET
	ft_putendl("");
	ft_putstr("content_img:\t");
	ft_print_address_color((intmax_t)window->content_img);
	ft_putendl("");
	ft_putstr("content_b_img:\t");
	ft_print_address_color((intmax_t)window->content_b_img);
	ft_putendl("");
	ft_putstr("\t\t\t\tbits per px:\t");
	C_RED
	ft_putnbr(window->bits_per_pixel);
	C_RESET
	ft_putendl("");
	ft_putstr("\t\t\t\tsize_line:\t");
	C_RED
	ft_putnbr(window->size_line);
	C_RESET
	ft_putendl("");
	ft_putstr("\t\t\t\tendian:\t\t");
	C_RED
	ft_putnbr(window->endian);
	C_RESET
	ft_putstr("\n");
	ft_putstr("\n");

}
void		ft_print_struct_mlx(t_mlx *window)
{
	ft_putstr("\n~~~~~");
	C_YELLOW
	ft_putstr(__func__);
	C_RESET
	ft_putstr("~~~~~\n");
	//CURSOR_RESET
	ft_putstr("WINDOW:\t");
	ft_print_address_color((intmax_t)window);
	ft_putendl("");
	ft_putstr("ptr:\t");
	ft_print_address_color((intmax_t)window->ptr);
	ft_putstr("\twidth:\t");
	C_CYAN
	ft_putnbr(window->width);
	C_RESET
	ft_putendl("");
	ft_putstr("win:\t");
	ft_print_address_color((intmax_t)window->win);
	ft_putstr("\theight:\t");
	C_RED
	ft_putnbr(window->height);
	C_RESET
	ft_putendl("");
	ft_putstr("img:\t");
	ft_print_address_color((intmax_t)window->img);
	ft_putendl("");
	ft_putstr("\n");
}
