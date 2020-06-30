#include "head.h"

void		arrow_slide_screen(t_mlx *mlx, int x, int y)
{
	float		width;
	float		shift_width;
	float		height;
	float		shift_height;

	width = (mlx->d.end.real - mlx->d.start.real);
	height = (mlx->d.end.imag - mlx->d.start.imag);
	shift_width = ZOOM_COEF * width;
	shift_height = ZOOM_COEF * height;
	ft_printf("Shift [%f %f]\n", shift_height, shift_width);
	if (x < 0)
		shift_width = -shift_width;
	else if (x == 0)
		shift_width = 0;
	if (y < 0)
		shift_height = -shift_height;
	else if (y == 0)
		shift_height = 0;
	ft_printf("Shift [%f %f]\n", shift_height, shift_width);
	mlx->d.start.real += shift_width;
	mlx->d.end.real += shift_width;
	mlx->d.start.imag += shift_height;
	mlx->d.end.imag += shift_height;
}

void	move_complex_window_center(t_mlx *mlx, int y, int x)
{
	float	height;
	float 	width;
	float	f_x;
	float 	f_y;

	ft_printf("Moving %d %d", x, y);
	////
	height = mlx->d.end.imag - mlx->d.start.imag;
	width = mlx->d.end.real - mlx->d.start.real;
	////
	f_x = pix_to_math(x, mlx->width, 0, width);
	f_y = pix_to_math(y, mlx->height, 0, height);
	ft_printf("\t-> %f %f\n", f_x, f_y);
	////
	////
	mlx->d.start.real = mlx->d.start.real + f_y;
	mlx->d.end.real   = mlx->d.end.real + f_y;
	mlx->d.start.imag = mlx->d.start.imag + f_x;
	mlx->d.end.imag   = mlx->d.end.imag + f_x;
	////
}

void move_content_window(t_mlx *mlx, int x, int y)
{
	int		movement_threshold;
	int		old_x;
	int		old_y;

	movement_threshold = 10;
	old_x = mlx->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD];
	old_y = mlx->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD];
	if (ft_abs(old_x - x) > movement_threshold
	&&  ft_abs(old_y - y) > movement_threshold)
	{
		move_complex_window_center(mlx, old_x - x, old_y - y);
		thread_fractol(mlx, NB_THREAD);
		render(mlx);
		mlx->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD] = x;
		mlx->mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD] = y;
	}
}
