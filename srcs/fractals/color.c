/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:50:28 by ldevelle          #+#    #+#             */
/*   Updated: 2020/07/01 19:02:28 by ezalos           ###   ########.fr       */
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

int			*ft_gradient(int color_1, int color_2, int len)
{
	int				*gradient;
	int				i;
	int				new;
	float			add[BGRA];

	i = 0;
	gradient = ft_memalloc(sizeof(int) * len);
	if (!gradient)
		return (NULL);
	gradient[i] = color_1;
	new = color_1;
	space_in_gradient(add, color_1, color_2, len);
	while (len > 1 && ++i < len - 1)
	{
		new = add_color(add, new);
		gradient[i] = new;
	}
	gradient[i] = color_2;
	return (gradient);
}

int		*palette_dracula(void)
{
	int		*gradient;
	int		dracula_1 = 0x00DC2424;
	int		dracula_2 = 0x004A569D;

	gradient = ft_gradient(dracula_1, dracula_2, LEN_GRAD);
	return (gradient);
}

int		*palette_sunrise(void)
{
	int		*gradient;
	int		sunrise_1 = 0x00FF512F;
	int		sunrise_2 = 0x00F09819;

	gradient = ft_gradient(sunrise_1, sunrise_2, LEN_GRAD);
	return (gradient);
}

int		*palette_skyline(void)
{
	int		*gradient;
	int		skyline_1 = 0x001488CC;
	int		skyline_2 = 0x002B32B2;

	gradient = ft_gradient(skyline_1, skyline_2, LEN_GRAD);
	return (gradient);
}

int		*ft_join_gradient(int *gradient, int *to_add, int size_grad, int size_add)
{
	int		*new;
	int		i;
	int		j;

	if (gradient == NULL)
		return (to_add);
	new = ft_memalloc(sizeof(int) * (size_grad + size_add));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size_grad)
	{
		new[i] = gradient[i];
		i++;
	}
	j = 0;
	while (j < size_add)
	{
		new[i + j] = to_add[j];
		j++;
	}
	return (new);
}

void	set_up_palettes(t_color *colors)
{
	colors->size_gradient = 0;
	colors->gradient = NULL;
	colors->dracula = palette_dracula();
	colors->sunrise = palette_sunrise();
	colors->skyline = palette_skyline();
	colors->gradient = ft_join_gradient(colors->gradient,\
		colors->dracula, colors->size_gradient, LEN_GRAD);
	colors->size_gradient += LEN_GRAD;
	colors->gradient = ft_join_gradient(colors->gradient,\
		colors->sunrise, colors->size_gradient, LEN_GRAD);
	colors->size_gradient += LEN_GRAD;
	colors->gradient = ft_join_gradient(colors->gradient,\
		colors->skyline, colors->size_gradient, LEN_GRAD);
	colors->size_gradient += LEN_GRAD;
}

int		colorize_fractol(int iter, t_mlx *mlx)
{
	int		color;

/*	if (iter == 0)
		color = ft_get_color(0, 204 + iter % 20, 153, 0);
	else if (iter > 0 && iter % 10 < 2)
		color = 0;
	else if (iter % 10 >= 2 && iter % 10 < 4)
		color = ft_get_color(0, 204 + iter % 20, 102, 0);
	else if (iter % 10 >= 4 && iter % 10 < 6)
		color = ft_get_color(0, 255, 255, 150 + iter % 20);
	else if (iter % 10 >= 6 && iter % 10 < 8)
		color = ft_get_color(0, 102, 0, 204);
	else
		color = 0;
*/
//	color = gradient[iter % len_gradient];//repasse plusieurs fois sur les couleurs
	color = mlx->fractal.colors.gradient[(int)(((float)iter / (float)mlx->fractal.max_iter) * (float)mlx->fractal.colors.size_gradient)];
//a un vrai min et un vrai max qui ne sont atteints que pour iter==0 et iter==max_iter
	return (color);
}
