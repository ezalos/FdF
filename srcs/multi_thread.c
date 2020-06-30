/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:01:40 by deyaberg          #+#    #+#             */
/*   Updated: 2020/06/30 17:53:34 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	*thread_func(void *data)
{
	t_multi_thread		*thread;
	// t_mlx				*mlx;

	thread = data;
	mandelbrot_loop_thread(thread->mlx, thread->zn, thread->start, thread->end);
	pthread_exit(NULL);
	return (NULL);
}

void	thread_data_setup(void *data, t_multi_thread *thread,
							int current_thread, int total_thread)
{
	t_mlx				*mlx;
	float				step;

	mlx = data;
	step = ((float)mlx->width / (float)total_thread);
	thread->mlx = mlx;
	thread->start = (step * (current_thread));
	thread->end = (step * (current_thread + 1));

	if (thread->start < 0)
		thread->start = 0;
	if (thread->end > (int)mlx->width)
		thread->end = mlx->width;

}

void	thread_fractol(t_mlx *mlx, int nb_thread)
{
	t_multi_thread		*thread;
	int					current_thread;

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
	current_thread = -1;
	while (++current_thread < nb_thread)
		if (pthread_join(thread[current_thread].pthread_nb, NULL))
			perror("pthread_join");
}
