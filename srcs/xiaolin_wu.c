/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:15:03 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/11 23:26:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

// integer part of x
int		ft_ipart(float x)
{
    return ((int)x);
}

int		ft_round(float x)
{
    return (ft_ipart(x + 0.5));
}

// fractional part of x
float	ft_fpart(float x)
{
    return (x - (int)x);
}

float	ft_rfpart(float x)
{
    return (1 - ft_fpart(x));
}

int		ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

unsigned int		ft_color_transparency(unsigned int color,
	unsigned char brightness)
{
	ft_memmove(&color + 3, &brightness, 1);
	return (color);
}

unsigned int		ft_plot(unsigned int color, float transparency)
{
	return (ft_color_transparency(color, transparency * 255));
}

void		ft_xiaolin_wu_init(t_xiaolin *xia, t_line *line, int color)
{
	int		dx;
	int		dy;

	xia->y[0] = line->limits[0].y;
	xia->y[1] = line->limits[1].y;
	xia->x[0] = line->limits[0].x;
	xia->x[1] = line->limits[1].x;

	xia->steep = (ft_abs(xia->y[1] - xia->y[0]) > ft_abs(xia->x[1] - xia->x[0]));
	if (xia->steep)
	{
	    ft_swap(&xia->x[0], &xia->y[0], sizeof(int));
	    ft_swap(&xia->x[1], &xia->y[1], sizeof(int));
	}
	if (xia->x[0] > xia->x[1])
	{
	    ft_swap(&xia->x[0], &xia->x[1], sizeof(int));
	    ft_swap(&xia->y[0], &xia->y[1], sizeof(int));
	}
	dx = xia->x[1] - xia->x[0];
	dy = xia->y[1] - xia->y[0];
	if (dx == 0)
		xia->gradient = 1;
	else
		xia->gradient = (float)dy / (float)dx;

	if (color == 16711680)
	{
		ft_printf("%~{255;155;155}%d/%d=%f%~{}\n", dy, dx, xia->gradient);
	}
}

void		ft_xiaolin_wu_start(t_mlx *mlx, t_xiaolin *xia, int color)
{
	int		xend;
	int		xgap;
	int		yend;

    xend = ft_round(xia->x[0]);
    yend = xia->y[0] + xia->gradient * (xend - xia->x[0]);
    xgap = ft_rfpart(xia->x[0] + 0.5);
    xia->xpxl[1] = xend ;// this will be used in the main loop
    xia->ypxl[1] = ft_ipart(yend);
    if (xia->steep)
	{
        ft_color_pixel(mlx, xia->ypxl[1],   xia->xpxl[1], ft_plot(color, ft_rfpart(yend) * xgap));
        ft_color_pixel(mlx, xia->ypxl[1] + 1, xia->xpxl[1],  ft_plot(color, ft_fpart(yend) * xgap));
	}
    else
	{
        ft_color_pixel(mlx, xia->xpxl[1], xia->ypxl[1]  , ft_plot(color, ft_rfpart(yend) * xgap));
        ft_color_pixel(mlx, xia->xpxl[1], xia->ypxl[1] + 1,  ft_plot(color, ft_fpart(yend) * xgap));
	}
	xia->intery = yend + xia->gradient;
}

void		ft_xiaolin_wu_end(t_mlx *mlx, t_xiaolin *xia, int color)
{
	int		xend;
	int		xgap;
	int		yend;

    xend = ft_round(xia->x[1]);
    yend = xia->y[1] + xia->gradient * (xend - xia->x[1]);
    xgap = ft_fpart(xia->x[1] + 0.5);
    xia->xpxl[2] = xend; //this will be used in the main loop
    xia->ypxl[2] = ft_ipart(yend);
    if (xia->steep)
	{
        ft_color_pixel(mlx, xia->ypxl[2]  , xia->xpxl[2], ft_plot(color, ft_rfpart(yend) * xgap));
        ft_color_pixel(mlx, xia->ypxl[2] + 1, xia->xpxl[2],  ft_plot(color, ft_fpart(yend) * xgap));
	}
    else
	{
        ft_color_pixel(mlx, xia->xpxl[2], xia->ypxl[2],  ft_plot(color, ft_rfpart(yend) * xgap));
        ft_color_pixel(mlx, xia->xpxl[2], xia->ypxl[2] + 1, ft_plot(color, ft_fpart(yend) * xgap));
	}
}

void		ft_xiaolin_wu_in(t_mlx *mlx, t_xiaolin *xia, int color)
{
	int		x;

	if (color == 16711680)
	{
		ft_printf("%~{}%s xpxl[1]%d < xpxl[1]%d\n", __func__, xia->xpxl[1], xia->xpxl[2]);
		ft_printf("x0: %d\tx1: %d\ty0: %d\ty1: %d\n", xia->x[0], xia->x[1], xia->y[0], xia->y[1]);
		ft_printf("steep: %d\tgradient: %f\tintery: %f\n", xia->steep, xia->gradient, xia->intery);
	}
	if (xia->steep)
	{
		x = xia->xpxl[1];
		while (++x < xia->xpxl[2])
		{
			ft_color_pixel(mlx, ft_ipart(xia->intery), x, ft_plot(color, ft_rfpart(xia->intery)));
			ft_color_pixel(mlx, ft_ipart(xia->intery) + 1, x, ft_plot(color, ft_fpart(xia->intery)));
			xia->intery += xia->gradient;
	   }
	}
	else
	{
		x = xia->xpxl[1];
		while (++x < xia->xpxl[2])
		{
			ft_color_pixel(mlx, x, ft_ipart(xia->intery), ft_plot(color, ft_rfpart(xia->intery)));
			ft_color_pixel(mlx, x, ft_ipart(xia->intery) + 1, ft_plot(color, ft_fpart(xia->intery)));
			xia->intery += xia->gradient;
		}
	}
}

int		ft_xiaolin_wu(t_mlx *mlx, t_line *line, int color)
{
	t_xiaolin	xia;

	ft_xiaolin_wu_init(&xia, line, color);
	ft_xiaolin_wu_start(mlx, &xia, color);
	ft_xiaolin_wu_end(mlx, &xia, color);
	ft_xiaolin_wu_in(mlx, &xia, color);
	return (1);
}
