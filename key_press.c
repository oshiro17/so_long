#include "so_long.h"
void move_player_utils(t_map **map, int go_x, int go_y, int y, t_info *info)
{
	if ((*map)->line[go_x] != '1')
	{
		if ((*map)->line[go_x] == 'E' && info->get_c == info->c_num)
			destroy_win(info);
		else if ((*map)->line[go_x] == 'E')
			return;
		else
		{
			if ((*map)->line[go_x] == 'C')
				info->get_c = info->get_c + 1;
			(*map)->line[go_x] = 'P';
			if (y == 1)
				(*map) = (*map)->pre;
			if (y == -1)
				(*map) = (*map)->next;
			(*map)->line[info->start_x] = '0';
			info->start_x = go_x;
			info->start_y = go_y;
		}
	}
}

void move_player(t_info *info, int x, int y)
{
	int go_x;
	int go_y;
	t_map *map;
	int i;

	i = 0;
	map = info->map;
	go_x = info->start_x + x;
	go_y = info->start_y + y;
	while (i < go_y)
	{
		map = map->next;
		i++;
	}
	move_player_utils(&map, go_x, go_y, y, info);
}


int key_press(int keycode, t_info *info)
{
	if (keycode == ESC)
		destroy_win(info);
	else if (keycode == W)
		move_player(info, 0, -1);
	else if (keycode == A)
		move_player(info, -1, 0);
	else if (keycode == S)
		move_player(info, 0, 1);
	else if (keycode == D)
		move_player(info, 1, 0);
	if (keycode == ESC || keycode == W || keycode == A || keycode == S || keycode == D)
	{
		info->count = info->count + 1;
		ft_printf("count:%d\n", info->count);
	}
	return (0);
}
