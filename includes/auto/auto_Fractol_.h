/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_Fractol_.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:42:44 by ezalos            #+#    #+#             */
/*   Updated: 2020/08/02 17:42:44 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_FRACTOL__H
# define AUTO_FRACTOL__H

int		parsing_fractol(int ac, char **av);
int		main(int ac, char **av);
void		thread_data_setup(void *data, t_multi_thread *thread,
		int current_thread, int total_thread);
void		*thread_func(void *data);
void		thread_fractol(t_mlx *mlx, int nb_thread);
int		anti_flood(void);
int		which_one(int direction);
void		zoom(int direction, float x, float y, t_mlx *mlx);
void		arrow_slide_screen(t_mlx *mlx, int x, int y);
void		move_complex_window_center(t_mlx *mlx, int y, int x);
void move_content_window(t_mlx *mlx, int x, int y);
int key_press(int keycode, t_mlx *mlx);
int key_release(int keycode, t_mlx *mlx);
void		mlx_hooks_and_loop(t_mlx *mlx);
int		mouse_press(int button, int x, int y, t_mlx *mlx);
int		mouse_release(int button, int x, int y, t_mlx *mlx);
long		get_time(void);
int mouse_move(int x, int y, t_mlx *mlx);
t_abs_coord		ft_check_window_size(t_mlx *mlx, size_t width, size_t height);
void		*ft_open_mlx(t_mlx *mlx, char *title, t_abs_coord size);
void		init_values(t_mlx *mlx);
t_mlx		*ft_init_mlx(char *title, size_t width, size_t height);
unsigned int		ft_get_color(unsigned char alpha, unsigned char red,
		unsigned char green, unsigned char blue);
void		ft_color_pixel(t_mlx_img *img, int x, int y, int color);
void		render(t_mlx *mlx);
int8_t		ft_add_img(t_mlx_all_img *img_grp, t_mlx_img *img);
t_mlx_img		*ft_create_img(t_mlx *mlx, char *title, t_abs_coord size, t_abs_coord pos);
void		ft_clean_and_exit(t_mlx *mlx);
void 		virgin_screen(t_mlx *mlx);
void		julia_react_to_mouse(t_mlx *mlx, int x, int y);
int		mandelbrot_equation(t_complex *zn, t_complex *c);
void		space_in_gradient(float add[BGRA], int color_1, int color_2, int len);
int		add_color(float add[BGRA], int old);
int		colorize_fractol(int iter, t_mlx *mlx);
int		ft_gt_colors(int clr1, int clr2, double val);
int		picasso(t_mlx *mlx, int iter, t_complex zn);
void		set_up_palettes(t_color *colors);
int		*palette_dracula(void);
int		*palette_sunrise(void);
int		*palette_skyline(void);
int		*ft_gradient(int color_1, int color_2, int len);
int		*ft_join_gradient(int *gradient, int *to_add, int size_grad, int size_add);
void		fractal_loop_thread(t_multi_thread *thread);
t_complex		complex_cos(t_complex *nb);
t_complex		complex_sin(t_complex *nb);
t_complex		complex_sinh(t_complex *nb);
t_complex		complex_exp(t_complex *nb);
t_complex		complex_ln(t_complex *nb);
t_complex		complex_square(t_complex *cpx);
t_complex		complex_cube(t_complex *cpx);
t_complex		complex_inverse(t_complex *cpx);
t_complex		complex_product(t_complex *n1, t_complex *n2);
double		complex_module(t_complex *cpx);
double		pix_to_math(double pixel, double size, double start, double end);

#endif
