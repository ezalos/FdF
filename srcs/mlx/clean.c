#include "head.h"

void		ft_clean_and_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_pointer, mlx->window_pointer);
	ft_clean_garbage();
	exit(0);
}

void 	virgin_screen(t_mlx *mlx)
{
	t_mlx_img			*img;

	img = ft_lst_reach_end(mlx->image_list)->content;
	ft_memset(img->my_image_data, 0, (mlx->size.hori * mlx->size.vert * 4));
	render(mlx);
}
