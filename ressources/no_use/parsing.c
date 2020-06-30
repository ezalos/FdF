/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:29:23 by amartino          #+#    #+#             */
/*   Updated: 2020/06/08 18:25:17 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"


int		ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}

static int		count_line(char *str)
{
	int		fd;
	int		ret;
	int		len;
	char	*line;

	len = 0;
	fd = open(str, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0 && ++len)
		ft_strdel(&line);
	close(fd);
	return (len);
}

static int		count_column(char *str)
{
	int		fd;
	int		ret;
	int		len;
	char	**str_map;
	char	*line;

	len = 0;
	str_map = NULL;
	fd = open(str, O_RDONLY);
	if ((ret = get_next_line(fd, &line)) > 0)
		str_map = ft_strsplit(line, ' ');
	len = -1;
	while (str_map[++len])
		ft_strdel(&str_map[len]);
	ft_memdel((void*)&str_map);
	close(fd);
	return (len);
}

int		fill_tab(char *str, t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx->map_nb_of_line = count_line(str);
	mlx->map_nb_of_column = count_column(str);
	if (!(mlx->map = (int**)malloc(sizeof(int*) * mlx->map_nb_of_line)))
		return (0);
	while (i < mlx->map_nb_of_line)
	{
		j = 0;
		if (!(mlx->map[i] = (int*)malloc(sizeof(int) * mlx->map_nb_of_column)))
			return (0);
		while (j < mlx->map_nb_of_column)
		{

		}

	}
	return (1);
}

/*
** int		parsing(char *str, t_mlx *mlx)
** {
** 	int		fd;
** 	int		ret;
** 	int		len;
** 	char	*str_map;
** 	char	*line;
** 	// char	**total;
**
** 	len = 0;
** 	str_map = NULL;
** 	fd = open(str, O_RDONLY);
** 	(void)mlx;
** 	while ((ret = get_next_line(fd, &line)) > 0)
** 	{
** 		if (str_map == NULL)
** 			str_map = ft_strdup(line);
** 		else
** 		{
** 			str_map = ft_strjoin(str_map, "\n");
** 			str_map = ft_strjoin(str_map, line);
** 		}
** 	}
** 	while (str_map[len])
** 	{
** 		ft_putchar(str_map[len]);
** 		len++;
** 	}
** 	// len = 0;
** 	// total = ft_strsplit(str_map, '\n');
** 	// printf("%s\n", total[0]);
** 	// fill_tab(str_map, mlx);
** 	return (1);
** }
*/

int		fdf_parsing(char *str, t_mlx *mlx)
{
	int		fd;
	int		ret;
	int		i;
	int		j;
	char	*line;
	char	**pre_line;

	fd = open(str, O_RDONLY);
	printf("%s\n", __func__);
	printf("%s\n", str);
	mlx->map_nb_of_line = count_line(str);
	mlx->map_nb_of_column = count_column(str);
	printf("fd : %d\nlin: %d\ncol: %d\n", fd, mlx->map_nb_of_line, mlx->map_nb_of_column);
	mlx->map = ft_memalloc(sizeof(int*) * (mlx->map_nb_of_line + 1));
	i =-1;
	while (++i < mlx->map_nb_of_line)
		mlx->map[i] = ft_memalloc(sizeof(int) * (mlx->map_nb_of_column + 1));
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0 && i < mlx->map_nb_of_line)
	{
		// printf("\nline n* %d\n", i);
		// _C_RED;
		// printf("%s\n", line);
		// _C_RESET;
		pre_line = ft_strsplit(line, ' ');
		j = -1;
		while (++j < mlx->map_nb_of_column && pre_line[j])
		{
			mlx->map[i][j] = ft_atoi(pre_line[j]);
			// printf("%-*d", 3, mlx->map[i][j]);
			ft_strdel(&pre_line[j]);
		}
		ft_memdel((void*)&pre_line);
		ft_memdel((void*)&line);
		i++;
	}
	close(fd);

	printf("\n");
	printf("\n");
	i = -1;
	while (++i < mlx->map_nb_of_line)
	{
		j = -1;
		while (++j < mlx->map_nb_of_column)
			if (mlx->map[i])
				printf("%d ", mlx->map[i][j]);
		printf("\n");
	}
	return (1);
}
