/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:07 by amartino          #+#    #+#             */
/*   Updated: 2019/06/10 16:24:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int key_event(int keycode, t_mlx *param)
{
	(void)param;
	ft_printf("Key event\n\tkey: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 53)
		exit(0);
	return (0);
}
