/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:35:20 by noshiro           #+#    #+#             */
/*   Updated: 2023/03/01 21:36:46 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_info	info;

	put_initial(&info);
	if (argc < 2)
		put_error_exit("no map\n");
	if (argc > 2)
		put_error_exit("too many arguments\n");
	check_error_map(argv[1], &(info.map), &info);
	get_map_info(&info);
	mlx_loop_hook(info.mlx, &first_print_image, &info);
	mlx_hook(info.win, 2, 1L << 0, &key_press, &info);
	mlx_hook(info.win, 17, 1L << 2, &destroy_win, &info);
	mlx_loop(info.mlx);
	exit(0);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }