
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

	if (x < 0 || x >= (int)mlx->width)
		return (-1);
	if (y < 0 || y >= (int)mlx->height)
		return (-1);
	lst = ft_lst_reach_end(mlx->image_list);
	img = lst->content;
	img->my_image_data[(img->width * y) + x] = color;
	return (color);
}
