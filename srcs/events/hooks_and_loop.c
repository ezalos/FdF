#include "head.h"

void		mlx_hooks_and_loop(t_mlx *mlx)
{
	mlx_hook(mlx->window_pointer, 2, 1L<<0, key_press, mlx);
	mlx_hook(mlx->window_pointer, 3, 1L<<1, key_release, mlx);
	mlx_hook(mlx->window_pointer, 4, 1L<<2, mouse_press, mlx);
	mlx_hook(mlx->window_pointer, 5, 1L<<3, mouse_release, mlx);
	mlx_hook(mlx->window_pointer, 6, 1L<<6, mouse_move, mlx);
	mlx_loop(mlx->mlx_pointer);
}
