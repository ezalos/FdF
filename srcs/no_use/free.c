/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 02:24:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 21:15:43 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void		ft_clean_and_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_pointer, mlx->window_pointer);
	ft_clean_garbage();
	exit(0);
}

void 	virgin_screen(t_mlx *mlx)
{
	t_img			*img;

	img = ft_lst_reach_end(mlx->image_list)->content;
	ft_memset(img->my_image_data, 0, (mlx->width * mlx->height * 4));
	render(mlx);
}
