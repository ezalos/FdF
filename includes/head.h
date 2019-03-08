/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:33 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 04:41:06 by ldevelle         ###   ########.fr       */
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
# define SIZE 1

# define OUR_CHOICE 3
# define UNIQ_BPP   4

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
# include "./../../libft/libft.h"
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
int					ft_nice_view(int choice, int y, int x);
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
int					ft_get_color(unsigned char alpha, unsigned char red,
						unsigned char green, unsigned char blue);

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
