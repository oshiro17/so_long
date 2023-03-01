#include "so_long.h"

void put_initial(t_info *info)
{
	info->count = 0;
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
	info->get_c = 0;
	info->map = NULL;
}

int put_image(t_info *info, char box, int x, int y)
{
	if (box == '1')
		mlx_put_image_to_window(info->mlx, info->win, info->block, IMG_SIZE * x, IMG_SIZE * y);
	else if (box == '0')
		mlx_put_image_to_window(info->mlx, info->win, info->floor, IMG_SIZE * x, IMG_SIZE * y);
	else if (box == 'E')
		mlx_put_image_to_window(info->mlx, info->win, info->exit, IMG_SIZE * x, IMG_SIZE * y);
	else if (box == 'C')
		mlx_put_image_to_window(info->mlx, info->win, info->coin, IMG_SIZE * x, IMG_SIZE * y);
	else if (box == 'P')
		mlx_put_image_to_window(info->mlx, info->win, info->human, IMG_SIZE * x, IMG_SIZE * y);
	return (x + 1);
}

int first_print_image(t_info *info)
{
	int x;
	int y;
	t_map *map;

	map = info->map;
	x = 0;
	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
			x = put_image(info, map->line[x], x, y);
		map = map->next;
		y++;
	}
	return (0);
}

void	image_into_memory(t_info *info, int *img_width, int *img_height)
{
	info->coin = mlx_xpm_file_to_image(info->mlx, "./img/coin.xpm", img_width, img_height);
	if (!info->coin)
		put_error_exit("mlx error");
	info->exit = mlx_xpm_file_to_image(info->mlx, "./img/exit.xpm", img_width, img_height);
	if (!info->exit)
		put_error_exit("mlx error");
	info->floor = mlx_xpm_file_to_image(info->mlx, "./img/floor.xpm", img_width, img_height);
	if (!info->floor)
		put_error_exit("mlx error");
	info->human = mlx_xpm_file_to_image(info->mlx, "./img/human.xpm", img_width, img_height);
	if (!info->human)
		put_error_exit("mlx error");
	info->block = mlx_xpm_file_to_image(info->mlx, "./img/block.xpm", img_width, img_height);
	if (!info->block)
		put_error_exit("mlx error");
}

void	get_map_info(t_info *info)
{
	int	img_width;
	int	img_height;

	info->mlx = mlx_init();
	if (!info->mlx)
		put_error_exit("malloc error");
	image_into_memory(info, &img_width, &img_height);
	info->win = mlx_new_window(info->mlx, img_width * info->width, img_height * info->height, "my_mlx");
	if (!info->win)
		put_error_exit("malloc error");
}

int	destroy_win(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_info info;

	put_initial(&info);
	if (argc < 2)
		put_error_exit("no map.");
	if (argc > 2)
		put_error_exit("too many arguments");
	check_error_map(argv[1], &(info.map), &info);
	get_map_info(&info);
	mlx_loop_hook(info.mlx, first_print_image, &info);
	mlx_hook(info.win, 2, 1L << 0, &key_press, &info);
	mlx_hook(info.win, 17, 1L << 2, &destroy_win, &info);
	mlx_loop(info.mlx);
	exit (0);
	return (0);

}
__attribute__((destructor)) static void destructor()
{
	system("leaks -q so_long");
}