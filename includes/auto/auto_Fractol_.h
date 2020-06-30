/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_Fractol_.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 23:53:41 by ezalos            #+#    #+#             */
/*   Updated: 2020/06/30 23:53:41 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_FRACTOL__H
# define AUTO_FRACTOL__H

int		parsing_fractol(int ac, char **av);
int		main(int ac, char **av);
void		*thread_func(void *data);
void		thread_data_setup(void *data, t_multi_thread *thread,
		int current_thread, int total_thread);
void		thread_fractol(t_mlx *mlx, int nb_thread);
int		which_one(int direction);
void		zoom(int direction, float x, float y, t_mlx *param);
void		move_complex_window_center(t_mlx *param, int y, int x);
void move_content_window(t_mlx *param, int x, int y);
unsigned int		ft_color_transparency(unsigned int color,
		unsigned char brightness);
unsigned int		ft_plot(unsigned int color, float transparency);
void		ft_xiaolin_wu_init(t_xiaolin *xia, t_line *line);
void		ft_xiaolin_wu_start(t_mlx *mlx, t_xiaolin *xia, int color);
void		ft_xiaolin_wu_end(t_mlx *mlx, t_xiaolin *xia, int color);
void		ft_xiaolin_wu_in(t_mlx *mlx, t_xiaolin *xia, int color);
int		ft_xiaolin_wu(t_mlx *mlx, t_line *line, int color);
int		ft_xone_equal_xtwo(t_mlx *mlx, t_line *line, int color);
void		ft_init_bresenham(t_bresenham *bre, t_line *line);
void		ft_bresenham_low(t_mlx *mlx, t_bresenham *bre, int color);
void		ft_bresenham_high(t_mlx *mlx, t_bresenham *bre, int color);
int		ft_bresenham(t_mlx *mlx, t_line *line, int color);
void		ft_print_struct_img(t_img *mlx);
void		ft_print_struct_mlx(t_mlx *mlx);
t_line		*ft_line(t_point *one, t_point *two);
double		ft_f_of_x(t_line *line, double x);
double		ft_get_decimal(double number);
int		ft_get_per_ntenth(double number, char precision);
int		ft_get_bound(double number);
int		ft_get_grey(int per_nth, char precision);
int		ft_draw_line(t_mlx *mlx, t_line *line, int color);
int		ft_how_far(double y, double x);
int		ft_line_gradient(t_mlx *mlx, t_line *line);
int		ft_my_line(t_mlx *mlx, t_line *line, int color);
int		ft_draw_circle(t_mlx *mlx, int x, int y, int radius);
void 		ft_draw_a_circle (t_mlx *mlx, int x, int y, int radius, unsigned int color);
int		ft_nice_view(int choice, int x, int y);
int		draw_lines_dynamically(int x, int y, t_mlx *param);
int		ft_get_percent(intmax_t x, intmax_t x_max);
int		ft_mlx_iter(t_mlx *mlx, int(*f)(t_mlx *, int, int));
t_point		*ft_get_point(int x, int y);
unsigned int		ft_get_color_pixel(t_mlx *mlx, int x, int y);
void		ft_show_all_colors(t_mlx *mlx);
int		ft_ponderate_mean(int x, int y, float mult);
int		ft_get_primary_color(int color, char nb);
int		ft_add_color_pixel(t_mlx *mlx, int x, int y, unsigned int new_color, float brightness);
int		ft_getnbr(char *str);
int		fill_tab(char *str, t_mlx *mlx);
int		fdf_parsing(char *str, t_mlx *mlx);
void		ft_clean_and_exit(t_mlx *mlx);
void 		virgin_screen(t_mlx *mlx);
int		ft_color_pixel_swag(t_mlx *mlx, int x, int y);
void		ft_draw_rectangle(t_mlx *mlx, t_point *a, t_point *b, unsigned int color);
void		ft_dynamic_rectangle(t_mlx *mlx, t_point *a);
int key_press(int keycode, t_mlx *param);
int key_release(int keycode, t_mlx *param);
void		mlx_hooks_and_loop(t_mlx *mlx);
int		mouse_press(int button, int x, int y, t_mlx *param);
int		mouse_release(int button, int x, int y, t_mlx *param);
int mouse_move(int x, int y, t_mlx *param);
void		ft_check_window_size(t_mlx *mlx, size_t width, size_t height);
void		*ft_open_mlx(t_mlx *mlx, char *title);
void		init_values(t_mlx *mlx);
t_img		*ft_create_img(t_mlx *mlx, char *title, size_t width, size_t height);
t_mlx		*ft_init_mlx(char *title, size_t width, size_t height);
unsigned int		ft_get_color(unsigned char alpha, unsigned char red,
		unsigned char green, unsigned char blue);
int		ft_color_pixel(t_mlx *mlx, int x, int y, int color);
void		render(t_mlx *mlx);
void		space_in_gradient(float add[3], int color_1, int color_2, int len);
int		add_color(float add[3], int old);
int		*ft_gradient(int color_1, int color_2);
int		*palette_dracula(void);
int		*palette_sunrise(void);
int		*palette_skyline(void);
int		*ft_join_gradient(int *gradient, int *to_add, int size);
void		set_up_palettes(t_mlx *mlx);
int		colorize_fractol(int iter, t_mlx *mlx);
void		julia_react_to_mouse(t_mlx *param, int x, int y);
int		mandelbrot_equation(t_complex *zn, t_complex *c);
t_complex		complex_square(t_complex *cpx);
t_complex		complex_cube(t_complex *cpx);
t_complex		complex_inverse(t_complex *cpx);
t_complex		complex_product(t_complex *n1, t_complex *n2);
double		complex_module(t_complex *cpx);
float		pix_to_math(float pixel, float size, float start, float end);
void		fractal_loop_thread(t_multi_thread *thread);

#endif
