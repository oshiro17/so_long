#include "so_long.h"

void go_up(t_info *info)
{
	int up_y;
	t_map *map;

	map = info->map;
	up_y = info->start_y - 1;
	while (up_y--)
		map = map->next;
	printf("%c\n",map->line[info->start_x]);
	if (map->line[info->start_x] == '1')
	{
		return ;
	}
	if (map->line[info->start_x] == '0')
	{
		map->line[info->start_x] = 'P';
		map->next->line[info->start_x] = '0';
		info->start_y = info->start_y - 1;
	}
	if (map->line[info->start_x] == 'E')
	{
		if (info->get_c == info->c_num)
		{
			ft_printf("乙乙");
			exit(0);
		}
		return;
	}
	if (map->line[info->start_x] == 'C')
	{
		map->line[info->start_x] = 'P';
		map->next->line[info->start_x] = '0';
		info->start_y = info->start_y - 1;
		info->get_c = info->get_c + 1;
	}
}

int key_press(int keycode,t_info *info)
{
	printf("%d\n",keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (keycode == W)
		go_up(info);
	return(0);
}
