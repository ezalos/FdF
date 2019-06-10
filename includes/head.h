/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:33 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 21:15:42 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

/*
******************************************************************************
**																			**
**								----------									**
**								 DEFINES									**
**								----------									**
**																			**
******************************************************************************
*/

/*
**************
**  GLOBAL	**
**************
*/
# define SIZE		0
# define PRECISION	3
# define SQRT_2		1.41421356237309504880
# define OUR_CHOICE	3
# define UNIQ_BPP	4
# define TRANS		10

/*
**************
**  WINDOW	**
**************
*/
# if SIZE == 0
#  define SIZE_WIDTH 800
#  define SIZE_HEIGTH 600
# elif SIZE == 1
#  define SIZE_WIDTH 1920
#  define SIZE_HEIGTH 1080
# elif SIZE == 2
#  define SIZE_WIDTH 2560
#  define SIZE_HEIGTH 1440
# elif SIZE == 3
#  define SIZE_WIDTH 800
#  define SIZE_HEIGTH 600
# else
#  define SIZE_WIDTH 600
#  define SIZE_HEIGTH 600
# endif

/*
**************
**  KEYCODE	**
**************
*/
# define ESC 		53
# define CONTROL 	256
# define DEL		117
# define SHIFT		257

/*
******************************************************************************
**																			**
**								----------									**
**								 INCLUDES									**
**								----------									**
**																			**
******************************************************************************
*/
# include "./../../libft/includes/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

/*
******************************************************************************
**																			**
**								----------									**
**								STRUCTURES									**
**								----------									**
**																			**
******************************************************************************
*/
typedef struct		s_mlx
{
	void			*mlx_pointer;
	void			*window_pointer;
	size_t			width;
	size_t			height;
	char			choice;
	char			key_array[280];
	char			mouse_array[8];
	t_list			*image_list;
}					t_mlx;

typedef struct		s_img
{
	int				*my_image_data;
	char			*title;
	void			*image_pointer;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
	size_t			width;
	size_t			height;
}					t_img;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_line
{
	double			a;
	double			b;
	t_point			limits[2];
}					t_line;

/*
******************************************************************************
**																			**
**								----------									**
**								PROTOTYPES									**
**								----------									**
**																			**
******************************************************************************
*/

/*
**************
**   INIT	**
**************
*/
t_mlx				*ft_init_mlx(char *title, size_t width, size_t height);

/*
**************
** 	 LINE   **
**************
*/
t_point				*ft_get_point(int x, int y);
t_line				*ft_line(t_point *one, t_point *two);
double				ft_f_of_x(t_line *line, double x);
double				ft_get_decimal(double number);
int					ft_get_per_ntenth(double number, char precision);
int					ft_color_pixel(t_mlx *mlx, int x, int y, int color);
int					ft_draw_line(t_mlx *mlx, t_line *line, int color);
int					ft_line_gradient(t_mlx *mlx, t_line *line);

/*
**************
** 	 TOOLS  **
**************
*/
int					ft_mlx_iter(t_mlx *mlx, int(*f)(t_mlx *, int, int));

/*
**************
** 	 EVENT  **
**************
*/
int					key_press(int keycode, t_mlx *param);
int					key_release(int keycode, t_mlx *param);
int					mouse_press(int button, int x, int y, t_mlx *param);
int					mouse_release(int button, int x, int y, t_mlx *param);
int					mouse_move(int x, int y, t_mlx *param);

/*
**************
** DISPLAY	**
**************
*/
int					ft_color_pixel_swag(t_mlx *mlx, int x, int y);
void				render(t_mlx *mlx);

/*
**************
** 	 PRINT  **
**************
*/
void				ft_print_struct_mlx(t_mlx *mlx);
void				ft_print_struct_img(t_img *mlx);

/*
**************
** 	 COLOR  **
**************
*/
unsigned int					ft_get_color(unsigned char alpha, unsigned char red,
						unsigned char green, unsigned char blue);

/*
**************
** 	 FREE   **
**************
*/
void				ft_clean_and_exit(t_mlx *mlx);
void 				virgin_screen(t_mlx *mlx);

/*
**************
**EASTER_EGG**
**************
*/
int					ft_nice_view(int choice, int x, int y);
int					draw_lines_dynamically(int x, int y, t_mlx *param);

#endif
