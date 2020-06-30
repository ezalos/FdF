#include "head.h"

void	move_complex_window_center(t_mlx *param, int y, int x)
{
	float	height;
	float 	width;
	float	f_x;
	float 	f_y;

	ft_printf("Moving %d %d", x, y);
	////
	height = param->d.end.imag - param->d.start.imag;
	width = param->d.end.real - param->d.start.real;
	////
	f_x = pix_to_math(x, param->width, 0, width);
	f_y = pix_to_math(y, param->height, 0, height);
	ft_printf("\t-> %f %f\n", f_x, f_y);
	////
	////
	param->d.start.real = param->d.start.real + f_y;
	param->d.end.real   = param->d.end.real + f_y;
	param->d.start.imag = param->d.start.imag + f_x;
	param->d.end.imag   = param->d.end.imag + f_x;
	////
}

void move_content_window(t_mlx *param, int x, int y)
{
	int		movement_threshold;
	int		old_x;
	int		old_y;

	movement_threshold = 10;
	old_x = param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD];
	old_y = param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD];
	if (ft_abs(old_x - x) > movement_threshold
	&&  ft_abs(old_y - y) > movement_threshold)
	{
		move_complex_window_center(param, old_x - x, old_y - y);
		thread_fractol(param, NB_THREAD);
		render(param);
		param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD] = x;
		param->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD] = y;
	}
}
