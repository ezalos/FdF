/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:07 by amartino          #+#    #+#             */
/*   Updated: 2019/06/10 19:38:41 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int key_press(int keycode, t_mlx *param)
{
	ft_printf("Key press\n\tkey: %d\n", keycode);
	// param->key_array[keycode] = '1';
	// printf("%c\n", param->key_array[keycode]);
	if (keycode == 53)
	{
		ft_clean_fdf(param);
		exit(0);
	}
	return (0);
}

int key_release(int keycode, t_mlx *param)
{
	(void)param;
	// param->key_array[keycode] = 0;
	ft_printf("Key release\n\tkey: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}
