#include "head.h"

int8_t		ft_add_img(t_mlx_all_img *img_grp, t_mlx_img *img)
{
	t_mlx_img		**old_images;

	if (img_grp->size_manager == 0)
	{
		img_grp->size_manager = IMG_MANAGER_INIT_SIZE;
		img_grp->images = ft_memalloc(sizeof(t_mlx_img*) * img_grp->size_manager);
	}
	if (img_grp->size_manager < img_grp->nb_images + 1)
	{
		img_grp->size_manager *= 2;
		old_images = img_grp->images;
		img_grp->images = ft_memalloc(sizeof(t_mlx_img*) * img_grp->size_manager);
		ft_memmove(&img_grp->images, &old_images, img_grp->nb_images * sizeof(t_mlx_img*));
		ft_memdel((void**)&old_images);
	}
	img_grp->images[img_grp->nb_images] = img;
	img_grp->nb_images++;
	return (TRUE);
}

t_mlx_img		*ft_create_img(t_mlx *mlx, char *title, t_abs_coord size, t_abs_coord pos)
{
	t_mlx_img			*img;

	img = ft_memalloc(sizeof(t_mlx_img));
	if (!(img->image_pointer = mlx_new_image(mlx->mlx_pointer,\
		size.hori, size.vert)))
		return (NULL);
	ft_printf("Img created\n");
	img->title = title;
	img->size = size;
	img->pos = pos;
	img->my_image_data = (int*)mlx_get_data_addr(img->image_pointer,\
		&img->bits_per_pixel, &img->size_line, &img->endian);
	return (img);
}
