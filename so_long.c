#include "so_long.h"

void	put_initial(t_info *info)
{
	info->c_num = 0;
	info->e_num = 0;
	info->height = 0;
	info->one_num = 0;
	info->p_num = 0;
	info->width = 0;
	info->zero_num = 0;
	info->block = NULL;
	info->coin = NULL;
	info->exit = NULL;
	info->floor = NULL;
	info->human = NULL;
	info->mlx = NULL;
	info->win = NULL;
	info->start_x = 0;
	info->start_y = 0;
}

void	first_print_image(t_map *map, t_info info)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < info.height)
	{
		x = 0;
		while (x < info.width)
		{
			if (map->line[x] == '1')
				mlx_put_image_to_window(info.mlx, info.win, info.block, IMG_SIZE * x , IMG_SIZE * y);
			else if(map->line[x] == '0')
				mlx_put_image_to_window(info.mlx, info.win, info.floor , IMG_SIZE * x , IMG_SIZE * y);
			else if (map->line[x] == 'E')
				mlx_put_image_to_window(info.mlx, info.win, info.exit, IMG_SIZE * x , IMG_SIZE * y);
			else if (map->line[x] == 'C')
				mlx_put_image_to_window(info.mlx, info.win, info.coin, IMG_SIZE * x , IMG_SIZE * y);
			else if (map->line[x] == 'P')
				mlx_put_image_to_window(info.mlx, info.win, info.human, IMG_SIZE * x , IMG_SIZE * y);
			x++;
		}
		map = map->next;
		y++;
	}
}
void get_map_info(t_info *info)
{
	int img_width;
	int img_height;

	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 500, 500, "my_mlx");
	info->coin = mlx_xpm_file_to_image(info->mlx, "./img/coin.xpm", &img_width,&img_height);
	info->exit = mlx_xpm_file_to_image(info->mlx, "./img/exit.xpm", &img_width, &img_height);
	info->floor = mlx_xpm_file_to_image(info->mlx, "./img/floor.xpm", &img_width, &img_height);
	info->human = mlx_xpm_file_to_image(info->mlx, "./img/human.xpm", &img_width, &img_height);
	info->block = mlx_xpm_file_to_image(info->mlx, "./img/block.xpm", &img_width, &img_height);
}

int	main (int argc, char **argv)
{
	t_map	*map;
	t_info	info;


	map = malloc(sizeof(t_map));
	put_initial(&info);
	map->line = NULL;
	map->next = NULL;
	map->pre = NULL;
	if (argc < 2)
		put_error_exit("no map.");
	if (argc > 2)
		put_error_exit("too many arguments");
	check_error_map(argv[1], &map, &info);
	// while(map->next)
	// {
	// 	printf("%s\n",map->line);
	// 	map= map->next;
	// }
	get_map_info(&info);
	first_print_image(map,info);
	mlx_loop(info.mlx);
	return (0);
	exit (0);
}