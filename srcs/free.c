/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 02:24:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 02:25:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		ft_clean_fdf(t_mlx *window)
{
	mlx_destroy_image(window->ptr, window->img);
	ft_clean_garbage();
	return (0);
}
