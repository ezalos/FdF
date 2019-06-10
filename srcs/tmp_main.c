
#include "fildefer.h"

double	set_offset(double *map_size)
{
	double	area;

	area = map_size[0] * map_size[1];
	if (area / 100 < 1)
		return (1);
	else
		return (area / 100);
}

t_mlx	*set_id(char *file)
{
	t_mlx	*id;

	id = (t_mlx*)malloc(sizeof(t_mlx));
	id->view = 0;
	id->file = file;
	id->max_height = 0;
	id->head = get_map_list(id);
	id->para_angle[0] = 85;
	id->para_angle[1] = 15;
	id->cam_angle[0] = to_radian(75);
	id->cam_angle[1] = to_radian(180);
	id->cam_angle[2] = to_radian(0);
	id->cam_pos[0] = (id->map_size[1]) * 0.5;
	id->cam_pos[2] = (id->map_size[0]) * 1.5;
	id->cam_pos[1] = tan(to_radian(75)) * sqrt(pow(id->cam_pos[0], 2)
			+ pow(id->cam_pos[1], 2));
	id->mlx = mlx_init();
	id->win = mlx_new_mlx(id->mlx, 1900, 1200, "FIL DE FER");
	id->offset = set_offset(id->map_size);
	id->colorfunct = &get_color_one;
	return (id);
}

int		main(int ac, char **av)
{
	t_mlx		*id;

	if (ac != 2)
		return (usage());
	else if (!(check_file(av[1])))
		return (0);
	else
	{
		id = set_id(av[1]);
		home_screen(id);
		set_cam_pos(id);
		mlx_key_hook(id->win, key_event, (void*)id);
		mlx_mouse_hook(id->win, mouse_event, (void*)id);
		mlx_loop(id->mlx);
	}
	return (0);
}
