/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:50:28 by ldevelle          #+#    #+#             */
/*   Updated: 2020/07/01 19:25:27 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	space_in_gradient(float add[BGRA], int color_1, int color_2, int len)
{
	add[FR_BLUE] = ((CAST_INT_(color_2))[FR_BLUE] - (CAST_INT_(color_1))[FR_BLUE]) / (len - 1);
	add[FR_GREEN] = ((CAST_INT_(color_2))[FR_GREEN] - (CAST_INT_(color_1))[FR_GREEN]) / (len - 1);
	add[FR_RED] = ((CAST_INT_(color_2))[FR_RED] - (CAST_INT_(color_1))[FR_RED]) / (len - 1);
	add[FR_ALPHA] = ((CAST_INT_(color_2))[FR_ALPHA] - (CAST_INT_(color_1))[FR_ALPHA]) / (len - 1);
}

int			add_color(float add[BGRA], int old)
{
	int	new;
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = (CAST_INT_(old))[FR_RED] + add[FR_RED];
	green = (CAST_INT_(old))[FR_GREEN] + add[FR_GREEN];
	blue = (CAST_INT_(old))[FR_BLUE] + add[FR_BLUE];
	alpha = (CAST_INT_(old))[FR_ALPHA] + add[FR_ALPHA];
	new = ft_get_color(alpha, red, green, blue);
	return (new);
}

int		colorize_fractol(int iter, t_mlx *mlx)
{
	t_color		*colors;
	int			color;
	int			index;

	colors = &mlx->fractal.colors;
	index = ((float)iter / (float)mlx->fractal.max_iter) * (float)colors->size_gradient;
//	color = gradient[iter % len_gradient];//repasse plusieurs fois sur les couleurs
	color = colors->gradient[index];
//a un vrai min et un vrai max qui ne sont atteints que pour iter==0 et iter==max_iter
	return (color);
}
