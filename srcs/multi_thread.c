/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:01:40 by deyaberge         #+#    #+#             */
/*   Updated: 2020/06/24 17:02:08 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	*thread_func(void *data)
{
	t_multi_thread		*thread;

	thread = data;
	mandelbrot_loop_thread(thread->mlx, thread->zn, thread->start, thread->end);
	return (NULL);
}

void	fractol_thread(t_mlx *mlx, int nb_thread)
{
	t_multi_thread		*thread;
	int					i;
	int					step;
	void				*ret;

	(void)ret;
	ret = NULL;
	thread = ft_memalloc(sizeof(t_multi_thread) * nb_thread);
	step = (mlx->width / nb_thread);
	i = -1;
	while (++i < nb_thread)
	{
		thread[i].mlx = mlx;
		thread[i].start = (step * (i));
		thread[i].end = step * (i + 1);
		if (thread[i].end > (int)mlx->width)
			thread[i].end = mlx->width;
		if (pthread_create(&thread[i].pthread_nb, NULL, &thread_func, &thread[i]) == -1)
			perror("pthread_create");
	}
	i = -1;
	while (++i < nb_thread)
		pthread_join(thread[i].pthread_nb, NULL);

	render(mlx);
}
