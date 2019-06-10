/*
** mlx.h for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue May 15 16:23:28 2007 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/


/*
** FR msg - FR msg - FR msg
**
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
** Merci de communiquer tout probleme de chargement d'image
** de ce type.
*/


#ifndef MLX_H

#define	MLX_H


void	*mlx_init();
/*
**  needed before everything else.
**  return (void *)0 if failed
*/


/*
** Basic actions
*/

void	*mlx_new_mlx(void *mlx_, int size_x, int size_y, char *title);
/*
**  return void *0 if failed
*/
int	mlx_clear_mlx(void *mlx_, void *win_);
int	mlx_pixel_put(void *mlx_, void *win_, int x, int y, int color);
/*
**  origin for x & y is top left corner of the mlx
**  y down is positive
**  color is 0x00RRGGBB
*/


/*
** Image stuff
*/

void	*mlx_new_image(void *mlx_,int width,int height);
/*
**  return void *0 if failed
**  obsolete : image2 data is stored using bit planes
**  void	*mlx_new_image2(void *mlx_,int width,int height);
*/
char	*mlx_get_data_addr(void *img_, int *bits_per_pixel,
			   int *size_line, int *endian);
/*
**  endian : 0 = sever X is little endian, 1 = big endian
**  for mlx_new_image2, 2nd arg of mlx_get_data_addr is number_of_planes
*/
int	mlx_put_image_to_mlx(void *mlx_, void *win_, void *img_,
				int x, int y);
unsigned int	mlx_get_color_value(void *mlx_, int color);


/*
** dealing with Events
*/

int	mlx_mouse_hook (void *win_, int (*funct_)(), void *param);
int	mlx_key_hook (void *win_, int (*funct_)(), void *param);
int	mlx_expose_hook (void *win_, int (*funct_)(), void *param);

int	mlx_loop_hook (void *mlx_, int (*funct_)(), void *param);
int	mlx_loop (void *mlx_);


/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
*/

int	mlx_string_put(void *mlx_, void *win_, int x, int y, int color,
		       char *string);
void	*mlx_xpm_to_image(void *mlx_, char **xpm_data,
			  int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_, char *filename,
			       int *width, int *height);
int	mlx_destroy_mlx(void *mlx_, void *win_);

int	mlx_destroy_image(void *mlx_, void *img_);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int	mlx_hook(void *win_, int x_event, int x_mask,
                 int (*funct)(), void *param);

int	mlx_do_key_autorepeatoff(void *mlx_);
int	mlx_do_key_autorepeaton(void *mlx_);
int	mlx_do_sync(void *mlx_);

#endif /* MLX_H */
