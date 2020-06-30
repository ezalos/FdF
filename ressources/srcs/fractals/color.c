/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:50:28 by ldevelle          #+#    #+#             */
/*   Updated: 2020/06/30 18:04:29 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
/*
void	space_in_gradient(float add[3], int color_1, int color_2, int len)
{
	add[FR_BLUE] = (((unsigned char*)&color_2)[0] -((unsigned char*)&color_1)[0]) / len - 1;
	add[FR_GREEN] = (((unsigned char*)&color_2)[1] -((unsigned char*)&color_1)[1]) / len - 1;
	add[FR_RED] = (((unsigned char*)&color_2)[2] -((unsigned char*)&color_1)[2]) / len - 1;
}

int			add_color(float add[3], int old)
{
	int	new;
	int	red;
	int	green;
	int	blue;

	red = ((unsigned char*)&old)[2] + add[FR_RED];
	green = ((unsigned char*)&old)[1] + add[FR_GREEN];
	blue = ((unsigned char*)&old)[0] + add[FR_BLUE];
	new = ft_get_color(0, red, green, blue);
	return (new);
}

int			*ft_gradient(int color_1, int color_2)
{
	int				*gradient;
	int				i;
	int				new;
	float			add[3];

	i = 0;
	gradient = ft_memalloc(sizeof(int) * LEN_GRAD);
	if (!gradient)
		return (NULL);
	gradient[i] = color_1;
	new = color_1;
	space_in_gradient(add, color_1, color_2, LEN_GRAD);
	while (LEN_GRAD > 1 && ++i < LEN_GRAD - 1)
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

	gradient = ft_gradient(dracula_1, dracula_2);
	return (gradient);
}

int		*palette_sunrise(void)
{
	int		*gradient;
	int		sunrise_1 = 0x00FF512F;
	int		sunrise_2 = 0x00F09819;

	gradient = ft_gradient(sunrise_1, sunrise_2);
	return (gradient);
}

int		*palette_skyline(void)
{
	int		*gradient;
	int		skyline_1 = 0x001488CC;
	int		skyline_2 = 0x002B32B2;

	gradient = ft_gradient(skyline_1, skyline_2);
	return (gradient);
}

int		*ft_join_gradient(int *gradient, int *to_add, int size)
{
	int		*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_printf("size = [%d]i, size + len = [%d]\n", size, size + LEN_GRAD);
	while (i < size)
	{
		ft_printf("gradient[%d] = [%x]\n", i, gradient[i]);
		i++;
	}
	i = 0;
	new = ft_memalloc(sizeof(int) * size + LEN_GRAD);
	if (!new)
		return (NULL);
	ft_printf("test1\n");
	if (gradient != NULL)
	{
		ft_printf("test2, gradient = [%p]\n", gradient);
		while (i < size)
		{
			new[i] = gradient[i];
			i++;
		}
	}
	ft_printf("i = %d, j = [%d]\n", i, j);
	ft_printf("test3, new = [%p], to_add = [%p]\n", new, to_add);
	while (j < LEN_GRAD)
	{
		new[i] = to_add[j];
	ft_printf("new[%d] = [%x]\n", i, new[i]);
		i++;
		j++;
	}
	ft_printf("THEN i = %d, j = [%d]\n", i, j);
	i = 0;
	ft_printf("test4, new = [%p]\n", new);
	while (i < size + LEN_GRAD)
	{
	ft_printf("FINAL new[%d] = [%x]\n", i, new[i]);
	i++;
	}
	ft_printf("test5\n");
	return (new);
}

void	set_up_palettes(t_mlx *mlx)
{
	mlx->size_gradient = 0;
	mlx->gradient = NULL;
	mlx->color.dracula = palette_dracula();
	mlx->color.sunrise = palette_sunrise();
	mlx->color.skyline = palette_skyline();
	ft_printf("*******dracula*******\n");
	mlx->gradient = ft_join_gradient(mlx->gradient, mlx->color.dracula, mlx->size_gradient);
	mlx->size_gradient += LEN_GRAD;
	ft_printf("*******sunrise*******\n");
	mlx->gradient = ft_join_gradient(mlx->gradient, mlx->color.sunrise, mlx->size_gradient);
	mlx->size_gradient += LEN_GRAD;
	ft_printf("*******skyline*******\n");
	mlx->gradient = ft_join_gradient(mlx->gradient, mlx->color.skyline, mlx->size_gradient);
	mlx->size_gradient += LEN_GRAD;
}*/

int		colorize_fractol(int iter, t_mlx *mlx)
{
	int		color;

	if (iter == 0)
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
	(void)mlx;
	return (color);
//	color = gradient[iter % len_gradient];//repasse plusieurs fois sur les couleurs
//	color = mlx->gradient[(iter / MAX_ITER) * 4];
//a un vrai min et un vrai max qui ne sont atteints que pour iter==0 et iter==max_iter
//	return (color);
}
