/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:01:40 by deyaberg          #+#    #+#             */
/*   Updated: 2020/08/02 22:09:15 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	thread_data_setup(void *data, t_multi_thread *thread,
							int current_thread, int total_thread)
{
	t_mlx				*mlx;
	float				step;

	mlx = data;
	step = ((float)mlx->size.hori / (float)total_thread);
	thread->mlx = mlx;
	thread->start = (step * (current_thread));
	thread->end = (step * (current_thread + 1));
	if (thread->start < 0)
		thread->start = 0;
	if (thread->end > (int)mlx->size.hori)
		thread->end = mlx->size.hori;
	thread->real_step = (mlx->fractal.dimension.end.real - mlx->fractal.dimension.start.real) / (double)mlx->size.hori;
	thread->imag_step = (mlx->fractal.dimension.end.imag - mlx->fractal.dimension.start.imag) / (double)mlx->size.vert;
	thread->thread_start = pix_to_math(thread->start, mlx->size.hori,
		mlx->fractal.dimension.start.real, mlx->fractal.dimension.end.real);
	thread->thread_end = pix_to_math(thread->end, mlx->size.hori,
		mlx->fractal.dimension.start.real, mlx->fractal.dimension.end.real);
	thread->c.real = mlx->fractal.c.real;
	thread->c.imag = mlx->fractal.c.imag;
	thread->img = mlx->fractal.images[current_thread];

}

void	*thread_func(void *data)
{
	t_multi_thread		*thread;

	thread = data;
	fractal_loop_thread(thread);
	pthread_exit(NULL);
	return (NULL);
}

void	thread_fractol(t_mlx *mlx, int nb_thread)
{
	t_multi_thread		*thread;
	int					current_thread;

	mlx->fractal.in_set_pxl = 0;
	thread = ft_memalloc(sizeof(t_multi_thread) * nb_thread);

	current_thread = -1;
	while (++current_thread < nb_thread)
	{
		thread_data_setup(mlx, &thread[current_thread],\
							current_thread, nb_thread);
		if (pthread_create(&thread[current_thread].pthread_nb, NULL,\
							&thread_func, &thread[current_thread]) == -1)
			perror("pthread_create");
	}

	while (current_thread--)
		if (pthread_join(thread[current_thread].pthread_nb, NULL))
			ft_printf("\n\n\n\n\n\n\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\npthread_join\n\n\\n\n\n\n\\n\n\n\n\n\\n\n\n\\n\n");

	double		ratio;

	ft_printf("size\thori %d\tvert %d\n", mlx->size.hori, mlx->size.vert);
	ratio = (double)mlx->fractal.in_set_pxl / (double)(mlx->size.hori * mlx->size.vert);
	ft_printf("Ratio: %f\n", ratio);
	// if (ratio < 0.85)
	// 	mlx->fractal.max_iter -= mlx->fractal.max_iter * 0.1;
	// else
	// 	mlx->fractal.max_iter += mlx->fractal.max_iter * 0.1;
	ft_printf("MAX_ITER %u\n", mlx->fractal.max_iter);
}
