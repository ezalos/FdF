#include "head.h"

void		arrow_slide_screen(t_mlx *mlx, int x, int y)
{
	float		width;
	float		shift_width;
	float		height;
	float		shift_height;

	width = (mlx->fractal.dimension.end.real - mlx->fractal.dimension.start.real);
	height = (mlx->fractal.dimension.end.imag - mlx->fractal.dimension.start.imag);
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
	mlx->fractal.dimension.start.real += shift_width;
	mlx->fractal.dimension.end.real += shift_width;
	mlx->fractal.dimension.start.imag += shift_height;
	mlx->fractal.dimension.end.imag += shift_height;
}

void	move_complex_window_center(t_mlx *mlx, int y, int x)
{
	double	height;
	double 	width;
	double	f_x;
	double 	f_y;

	ft_printf("Moving %d %d", x, y);
	////
	height = mlx->fractal.dimension.end.imag - mlx->fractal.dimension.start.imag;
	width = mlx->fractal.dimension.end.real - mlx->fractal.dimension.start.real;
	////
	ft_printf("\tH%f W%f", height, width);
	f_x = pix_to_math(x, mlx->width, 0, width);
	f_y = pix_to_math(y, mlx->height, 0, height);
	ft_printf("\t-> %f %f\n", f_x, f_y);
	////
	////
	mlx->fractal.dimension.start.real = mlx->fractal.dimension.start.real + f_y;
	mlx->fractal.dimension.end.real   = mlx->fractal.dimension.end.real + f_y;
	mlx->fractal.dimension.start.imag = mlx->fractal.dimension.start.imag + f_x;
	mlx->fractal.dimension.end.imag   = mlx->fractal.dimension.end.imag + f_x;
	////
}

void move_content_window(t_mlx *mlx, int x, int y)
{
	int		movement_threshold;
	int		old_x;
	int		old_y;

	movement_threshold = 1;
	old_x = mlx->keys.mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD];
	old_y = mlx->keys.mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD];
	if (ft_abs(old_x - x) > movement_threshold
	&&  ft_abs(old_y - y) > movement_threshold)
	{
		move_complex_window_center(mlx, old_x - x, old_y - y);
		thread_fractol(mlx, NB_THREAD);
		render(mlx);
		mlx->keys.mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_X_COORD] = x;
		mlx->keys.mouse_array[MLX_MOUSE_CLICK_LEFT][MLX_MOUSE_Y_COORD] = y;
	}
}
