/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:50:28 by ldevelle          #+#    #+#             */
/*   Updated: 2020/07/02 01:33:15 by ezalos           ###   ########.fr       */
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

# define DIVLOG 1.44269504088896338700465094007086008787155151367187500000000000
# define PI 3.14159265359

int			ft_gt_colors(int clr1, int clr2, double val)
{
	int		r;
	int		g;
	int		b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor((double)((clr1 >> 16) & 0xFF) -
			(((double)((clr1 >> 16) & 0xFF) - (double)((clr2 >> 16) & 0xFF)) * val));
	g = floor((double)((clr1 >> 8) & 0xFF) -
			(((double)((clr1 >> 8) & 0xFF) - (double)((clr2 >> 8) & 0xFF)) * val));
	b = floor((double)((clr1) & 0xFF) - (((double)((clr1) & 0xFF) \
					- (double)((clr2) & 0xFF)) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int		picasso(t_mlx *mlx, int iter, t_complex zn)
{
	t_color		*colors;
	int			gradient;
	int			color;
	double		index;
	double		mod;;

	colors = &mlx->fractal.colors;
	gradient = (int)((float)iter) % 3;
	mod = complex_module(&zn);
	if (mod <= 4)
	{
		color = 0;
		mlx->fractal.in_set_pxl++;
	}
	else if (0)
	{
		index = log((log(mod) * 0.50f) * DIVLOG) * DIVLOG;
		if (index < 0.0f)
			index = 0.0f;
		index *= 0.10f;
		if ((int)index < 0 || index > 5)
			index = ((double)((int)((double)index * 1000000) % 5000000) / 1000000);
		color = ft_gt_colors(colors->gradient[(iter + 1) % colors->size_gradient],
		colors->gradient[(iter) % colors->size_gradient], index);
	}
	else
	{
		index = (mod - 4);
		color = colors->louis_grad[gradient][((int)(index / 3)) % LEN_GRAD];
	}
	return (color);
}
