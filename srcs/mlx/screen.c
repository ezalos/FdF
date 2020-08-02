
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

void				ft_color_pixel(t_mlx_img *img, int x, int y, int color)
{
	x -= img->pos.hori;
	y -= img->pos.vert;
	if (x >= 0 && x < (int)img->size.hori)
		if (y >= 0 && y < (int)img->size.vert)
			img->my_image_data[(img->size.hori * y) + x] = color;
}

void	render(t_mlx *mlx)
{
	t_mlx_img			*img;
	size_t				i;

	i = 0;
	while (i < mlx->images_manager.nb_images)
	{
		img = mlx->images_manager.images[i];
		mlx_put_image_to_window(mlx->mlx_pointer, mlx->window_pointer,\
			img->image_pointer,\
			img->pos.vert, img->pos.hori);
		i++;
	}
}
