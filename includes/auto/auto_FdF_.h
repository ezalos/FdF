/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_FdF_.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:07:41 by deyaberg          #+#    #+#             */
/*   Updated: 2020/06/24 16:15:01 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_FDF__H
# define AUTO_FDF__H

int		ft_color_pixel_swag(t_mlx *mlx, int x, int y);
void		render(t_mlx *mlx);
int		ft_getnbr(char *str);
int		fill_tab(char *str, t_mlx *mlx);
int		fdf_parsing(char *str, t_mlx *mlx);
void		ft_print_struct_img(t_img *mlx);
void		ft_print_struct_mlx(t_mlx *mlx);
int		ft_get_percent(intmax_t x, intmax_t x_max);
int		ft_mlx_iter(t_mlx *mlx, int(*f)(t_mlx *, int, int));
void		ft_draw_rectangle(t_mlx *mlx, t_point *a, t_point *b, unsigned int color);
void		ft_dynamic_rectangle(t_mlx *mlx, t_point *a);
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
void	mandel_thread(t_mlx *mlx, int nb_thread);
void	mandelbrot_loop_thread(t_mlx *mlx, t_complex zn, int start, int end);
unsigned int		ft_color_transparency(unsigned int color,
		unsigned char brightness);
unsigned int		ft_plot(unsigned int color, float transparency);
void		ft_xiaolin_wu_init(t_xiaolin *xia, t_line *line);
void		ft_xiaolin_wu_start(t_mlx *mlx, t_xiaolin *xia, int color);
void		ft_xiaolin_wu_end(t_mlx *mlx, t_xiaolin *xia, int color);
void		ft_xiaolin_wu_in(t_mlx *mlx, t_xiaolin *xia, int color);
int		ft_xiaolin_wu(t_mlx *mlx, t_line *line, int color);
void		ft_clean_and_exit(t_mlx *mlx);
void 		virgin_screen(t_mlx *mlx);
int		ft_draw_circle(t_mlx *mlx, int x, int y, int radius);
void 		ft_draw_a_circle (t_mlx *mlx, int x, int y, int radius, unsigned int color);
int		ft_xone_equal_xtwo(t_mlx *mlx, t_line *line, int color);
void		ft_init_bresenham(t_bresenham *bre, t_line *line);
void		ft_bresenham_low(t_mlx *mlx, t_bresenham *bre, int color);
void		ft_bresenham_high(t_mlx *mlx, t_bresenham *bre, int color);
int		ft_bresenham(t_mlx *mlx, t_line *line, int color);
int		ft_nice_view(int choice, int x, int y);
int		draw_lines_dynamically(int x, int y, t_mlx *param);
void		zoom(int direction, float x, float y, t_mlx *param);
void		ft_check_window_size(t_mlx *mlx, size_t width, size_t height);
void		*ft_open_mlx(t_mlx *mlx, char *title);
void		init_values(t_mlx *mlx);
t_img		*ft_create_img(t_mlx *mlx, char *title, size_t width, size_t height);
t_mlx		*ft_init_mlx(char *title, size_t width, size_t height);
int		mandelbrot_equation(t_complex *zn, t_complex *c);
float		pix_to_math(float pixel, float size, float start, float end);
float		math_to_pix(int nb, int size, float start, float end, float size_small);
void		mandelbrot_loop(t_mlx *mlx);
int		main(int ac, char **av);
int key_press(int keycode, t_mlx *param);
int key_release(int keycode, t_mlx *param);
t_point		*ft_get_point(int x, int y);
unsigned int		ft_get_color_pixel(t_mlx *mlx, int x, int y);
void		ft_show_all_colors(t_mlx *mlx);
int		ft_color_pixel(t_mlx *mlx, int x, int y, int color);
int		ft_ponderate_mean(int x, int y, float mult);
int		ft_get_primary_color(int color, char nb);
int		ft_add_color_pixel(t_mlx *mlx, int x, int y, unsigned int new_color, float brightness);
int		mouse_press(int button, int x, int y, t_mlx *param);
int		mouse_release(int button, int x, int y, t_mlx *param);
int mouse_move(int x, int y, t_mlx *param);
unsigned int		ft_get_color(unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue);

#endif
