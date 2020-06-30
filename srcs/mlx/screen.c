
#include "head.h"

unsigned int		ft_get_color(unsigned char alpha, unsigned char red,
	unsigned char green, unsigned char blue)
{
	unsigned int				color;
	unsigned char				bad_col[4];

	bad_col[3] = alpha;
	bad_col[2] = red;
	bad_col[1] = green;
	bad_col[0] = blue;
	ft_memmove(&color, bad_col, 4);
	return (color);
}

int					ft_color_pixel(t_mlx *mlx, int x, int y, int color)
{
	t_list	*lst;
	t_img	*img;

	lst = ft_lst_reach_end(mlx->image_list);
	img = lst->content;
	if (x < 0 || x >= (int)img->width)
		return (-1);
	if (y < 0 || y >= (int)img->height)
		return (-1);
	img->my_image_data[(img->width * y) + x] = color;
	return (color);
}

void	render(t_mlx *mlx)
{
	t_img			*img;

	img = mlx->image_list->content;
	// mlx_clear_window(mlx->mlx_pointer, mlx->window_pointer);
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->window_pointer,\
		img->image_pointer, img->pos_height, img->pos_width);
}
