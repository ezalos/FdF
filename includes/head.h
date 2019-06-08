/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:33 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/08 18:01:51 by ldevelle         ###   ########.fr       */
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
# define SIZE		1
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
** SIZE_WIDTH == X
** SIZE_HEIGTH == Y
*/

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
	void			*ptr;
	void			*win;
	size_t			width;
	size_t			height;
	char			choice;
	t_list			*img;
}					t_mlx;

typedef struct		s_img
{
	int				*content_img;
	int				*content_b_img;
	char			*title;
	void			*img;
	void			*b_img;
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
t_mlx				*ft_init_window(char *title, size_t width, size_t height);

/*
**************
** DISPLAY	**
**************
*/
int					ft_nice_view(int choice, int x, int y);
int					ft_display_swag(t_mlx *window, int x, int y);

/*
**************
** 	 PRINT  **
**************
*/
void				ft_print_struct_mlx(t_mlx *window);
void				ft_print_struct_img(t_img *window);

/*
**************
** 	 COLOR  **
**************
*/
unsigned int					ft_get_color(unsigned char alpha, unsigned char red,
						unsigned char green, unsigned char blue);

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
int					ft_display(t_mlx *window, int x, int y, int color);
int					ft_draw_line(t_mlx *window, t_line *line, int color);
int					ft_line_gradient(t_mlx *window, t_line *line);

/*
**************
** 	 TOOLS  **
**************
*/
int					ft_window_iter(t_mlx *window, int(*f)(t_mlx *, int, int));

/*
**************
** 	 FREE   **
**************
*/
int					ft_clean_fdf(t_mlx *window);

#endif
