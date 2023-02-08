/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:48:10 by panti             #+#    #+#             */
/*   Updated: 2023/02/08 10:21:11 by panti            ###   ########.fr       */
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
	printf("%s\n",map->line);
	printf("info->height::%d\n",info.height);
	exit (0);
}