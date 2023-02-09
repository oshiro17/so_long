/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:48:10 by panti             #+#    #+#             */
/*   Updated: 2023/02/09 23:41:30 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

int	main (int argc, char **argv)
{
	t_map	*map;
	t_info	info;
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	int img_width;
	int img_height;


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
	while(map->next)
	{
		printf("%s\n",map->line);
		map= map->next;
	}
		mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./img/coin.xpm", &img_width, &img_height);
	printf("%d\n",img_width);
	img2 = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./img/floor.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./img/human.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./img/block.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, IMG_SIZE*0, IMG_SIZE*0);
	mlx_put_image_to_window(mlx, win, img2, IMG_SIZE*1, IMG_SIZE*0);
	mlx_put_image_to_window(mlx, win, img3, IMG_SIZE*2, IMG_SIZE*0);
	mlx_put_image_to_window(mlx, win, img4, IMG_SIZE*3, IMG_SIZE*1);
	mlx_put_image_to_window(mlx, win, img5, IMG_SIZE*4, IMG_SIZE*1);
	mlx_loop(mlx);
	return (0);
	exit (0);
}