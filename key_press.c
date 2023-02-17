#include "so_long.h"

// char up_is_block(t_info *info)
// {
// 	int up_x;
// 	int up_y;
// 	t_map *map;

// 	map = info->map;
// 	up_x = info->human_x;
// 	up_y = info->human_y - 1;
// 	while (up_y--)
// 	map = map->next;
// 	if (map->line[up_x] == '1')
// 		return ('1');
// 	if (map->line[up_x] == '0')
// 		return ('0');
// 	if (map->line[up_x] == 'E')
// 		return ('0');
// 	if (map->line[up_x] == '')
// 		return ('0');
// 	if (map->line[up_x] == '0')
// 		return ('0');
// }


// void	go_up(t_info *info)
// {
// 	t_map	*map;
// 	char	box;
// 	int	up_x;
// 	int	up_y;

// 	map = info->map;
// 	up_x = info->human_x;
// 	up_y = info->human_y - 1;
// 	if (!up_is_(info))
// 		return ;
// 	while (up_y--)
// 		map = map->next;
// 	box = map->line[up_x];
// 	map->line[up_x] = 'P'
	
// }

int key_press(int keycode,t_info *info)
{
	printf("%d\n",keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	// if (keycode == W)
	// 	go_up(info);
	return(0);
}
