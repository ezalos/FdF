/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 02:24:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 16:43:45 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_clean_fdf(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_pointer, mlx->window_pointer);
	ft_clean_garbage();
	return (0);
}
