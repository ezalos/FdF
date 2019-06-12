/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:07 by amartino          #+#    #+#             */
/*   Updated: 2019/06/12 23:06:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int key_press(int keycode, t_mlx *param)
{
	// printf("%d\n", keycode);
	param->key_array[keycode] = 1;
	if (keycode == ESC)
		ft_clean_and_exit(param);
	if (keycode == DEL)
		virgin_screen(param);
	if (keycode == 71)
		ft_show_all_colors(param);
	if (keycode == 49)
		ft_draw_circle(param, param->width / 2, param->height / 2, 500);
	return (0);
}

int key_release(int keycode, t_mlx *param)
{
	param->key_array[keycode] = 0;
	return (0);
}
