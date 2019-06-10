/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:38:40 by amartino          #+#    #+#             */
/*   Updated: 2019/06/10 19:36:47 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			mouse_press(int button, int x, int y, t_mlx *param)
{
	// if (button == 1 && param->key_array[CONTROL] == 1)
	// 	draw_lines_dynamically(button, x, y, param);
	param->mouse_array[button] = '1';
	printf("mouse buttom %c\n", param->mouse_array[button]);
	if (button == 1)
	{
		ft_color_pixel((param), x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	return (1);
}

int			mouse_release(int button, int x, int y, t_mlx *param)
{
	if (button == 1)
	{
		ft_color_pixel((param), x, y, 0x00ffffff);
		render(param);
		return (1);
	}
	return (1);
}


// int			draw_lines_dynamically(int button, int x, int y, t_mlx *param)
// {
// 	t_list			*lst;
// 	t_img			*img;
// 	t_mlx			*mlx;
// 	t_line 			*line;
// 	t_point 		*actual;
// 	static t_point 	*last;
//
// 	ft_printf("Mouse event\n\tbutton: %d\n\tx: %d\n\ty: %d\n", button, x, y);
// 	mlx = param;
// 	lst = ft_lst_reach_end(mlx->image_list);
// 	img = lst->content;
// 	actual = ft_get_point(x, y);
// 	if (actual && last)
// 	{
// 		line = ft_line(last, actual);
// 		ft_line_gradient(mlx, line);
// 		render(mlx);
// 	}
// 	else
// 		img->my_image_data[(img->width * y) + x] = 0x00ffffff;
// 	last = actual;
// 	return (0);
// }
