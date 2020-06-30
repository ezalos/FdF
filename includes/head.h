/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:33 by ldevelle          #+#    #+#             */
/*   Updated: 2020/06/30 23:46:07 by ezalos           ###   ########.fr       */
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
# define SIZE		4
# define FR_BLUE	0
# define FR_GREEN	1
# define FR_RED		2
# define FR_NONE	3
# define LEN_GRAD	6
# define MAX_ITER	50
# define NB_THREAD	4
# define PRECISION	3
# define ZOOM_COEF	0.1
# define Z_FORWARD	5
# define Z_BACKWARD	4
# define SQRT_2		1.41421356237309504880
# define OUR_CHOICE	3
# define UNIQ_BPP	4
# define TRANS		10
# define PX_WHITE	0x00ffffff

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE -1

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
#  define SIZE_WIDTH 1500
#  define SIZE_HEIGTH 1000
# elif SIZE == 4
#  define SIZE_WIDTH 1000
#  define SIZE_HEIGTH 750
# else
#  define SIZE_WIDTH 600
#  define SIZE_HEIGTH 600
# endif


/*
******************************************************************************
**																			**
**								----------									**
**								 INCLUDES									**
**								----------									**
**																			**
******************************************************************************
*/
# include "./libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "keycodes.h"

/*
******************************************************************************
**																			**
**								----------									**
**								STRUCTURES									**
**								----------									**
**																			**
******************************************************************************
*/
// a + ib //
typedef struct		s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct		s_dimension
{
	t_complex		start;
	t_complex		end;
}					t_dimension;

typedef	struct		s_color
{
	int				*dracula;
	int				*sunrise;
	int				*aqua_marine; //(0x1A2980 && 0x26D0CE)
	int				*aubergine; //(0xAA076B && 0x61045F)
	int				*mango; // (0xF09819 && 0xEDDE5D)
	int				*skyline; // (0x1488CC && 0x2B32B2)
}					t_color;

typedef struct		s_mlx_keys
{
	char			key_array[280];
	int				mouse_array[10][3];
}					t_mlx_keys;

typedef struct		s_fractal
{
	t_complex		zn;
	t_complex		c;
	t_dimension		d;
}					t_fractal;

typedef struct		s_mlx
{
	void			*mlx_pointer;
	void			*window_pointer;
	t_list			*image_list;
	int				**map;
	size_t			width;
	size_t			height;
	int				max_iter;
	int				map_nb_of_line;
	int				map_nb_of_column;
	char			choice;
	char			key_array[280];
	int				mouse_array[8][3];
	unsigned int	saved_color;
	unsigned int	circle_size;
	t_complex		zn;
	t_complex		c;
	int				mandelbrot;
	int				free_julia;
	t_dimension		d;
	t_color			color;
	int				*gradient;
	size_t			size_gradient;
}					t_mlx;

typedef struct		s_multi_thread
{
	pthread_t		pthread_nb;
	t_mlx			*mlx;
	t_complex		zn;
	int				start;
	int				end;
	int				pxl_width;
	int				pxl_height;
	double			real_step;
	double			imag_step;
	double			thread_end;
	double			thread_start;
	t_complex		c;
	t_complex		pos;
}					t_multi_thread;

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

typedef struct		s_xiaolin
{
	int 	x[3];
	int 	xpxl[3];
	int 	y[3];
	int 	ypxl[3];
	int 	steep;
	float 	gradient;
	float 	intery;
}					t_xiaolin;

typedef struct		s_bresenham
{
	int 	x[3];
	int 	y[3];
	int		dx;
	int		dy;
	int		yi;
	int		xi;
	int		d;
}					t_bresenham;

typedef struct		s_line
{
	double			a;
	double			b;
	t_point			limits[2];
}					t_line;

# include "auto_Fractol.h"

/*
******************************************************************************
**																			**
**								----------									**
**								PROTOTYPES									**
**								----------									**
**																			**
******************************************************************************
*/

// /*
// **************
// **   INIT	**
// **************
// */
// t_mlx				*ft_init_mlx(char *title, size_t width, size_t height);
//
//
// /*
// **************
// ** 	POINT   **
// **************
// */
// t_point				*ft_get_point(int x, int y);
// int					ft_color_pixel(t_mlx *mlx, int x, int y, int color);
// int					ft_color_pixel_if_brighter(t_mlx *mlx, int x, int y,
// 					int color);
// int					ft_add_color_pixel(t_mlx *mlx, int x, int y,
// 					unsigned int new_color, float brightness);
// unsigned int		ft_get_color_pixel(t_mlx *mlx, int x, int y);
//
// /*
// **************
// ** 	 LINE   **
// **************
// */
// int					ft_xiaolin_wu(t_mlx *mlx, t_line *line, int color);
// int					ft_my_line(t_mlx *mlx, t_line *line, int color);
// int					ft_bresenham(t_mlx *mlx, t_line *line, int color);
// t_line				*ft_line(t_point *one, t_point *two);
// double				ft_f_of_x(t_line *line, double x);
// double				ft_get_decimal(double number);
// int					ft_get_per_ntenth(double number, char precision);
// int					ft_draw_line(t_mlx *mlx, t_line *line, int color);
// int					ft_line_gradient(t_mlx *mlx, t_line *line);
//
// /*
// **************
// ** 	SHAPE   **
// **************
// */
// int					ft_draw_circle(t_mlx *mlx, int x, int y, int radius);
// void 				ft_draw_a_circle (t_mlx *mlx, int x, int y, int radius,
// 					unsigned int color);
// void				ft_dynamic_rectangle(t_mlx *mlx, t_point *a);
// void				ft_draw_rectangle(t_mlx *mlx, t_point *a, t_point *b,
// 					unsigned int color);
//
// /*
// **************
// ** 	 TOOLS  **
// **************
// */
// int					ft_mlx_iter(t_mlx *mlx, int(*f)(t_mlx *, int, int));
//
// /*
// **************
// ** 	 EVENT  **
// **************
// */
// // int					mouse_event(int button, int x, int y, t_mlx *param);
// // int					key_event(int keycode, t_mlx *param);
// int					key_press(int keycode, t_mlx *param);
// int					key_release(int keycode, t_mlx *param);
// int					mouse_press(int button, int x, int y, t_mlx *param);
// int					mouse_release(int button, int x, int y, t_mlx *param);
// int					mouse_move(int x, int y, t_mlx *param);
//
// /*
// **************
// ** DISPLAY	**
// **************
// */
// int					ft_color_pixel_swag(t_mlx *mlx, int x, int y);
// void				render(t_mlx *mlx);
//
// /*
// **************
// ** 	 PRINT  **
// **************
// */
// void				ft_print_struct_mlx(t_mlx *mlx);
// void				ft_print_struct_img(t_img *mlx);
//
// /*
// **************
// ** 	 COLOR  **
// **************
// */
// unsigned int		ft_get_color(unsigned char alpha, unsigned char red,
// 					unsigned char green, unsigned char blue);
// void				ft_show_all_colors(t_mlx *mlx);
//
// /*
// **************
// ** 	 FREE   **
// **************
// */
// void				ft_clean_and_exit(t_mlx *mlx);
// void 				virgin_screen(t_mlx *mlx);
//
// /*
// **************
// ** 	PARSING **
// **************
// */
// int					fdf_parsing(char *str, t_mlx *mlx);
//
// /*
// **************
// **EASTER_EGG**
// **************
// */
// int					ft_nice_view(int choice, int x, int y);
// int					draw_lines_dynamically(int x, int y, t_mlx *param);

#endif
