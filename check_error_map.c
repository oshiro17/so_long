/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:07:29 by noshiro           #+#    #+#             */
/*   Updated: 2023/03/01 21:39:59 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_start(t_map *map, t_info *info)
{
	info->start_y = 0;
	while (map)
	{
		info->start_x = 0;
		while (map->line[info->start_x])
		{
			if (map->line[info->start_x] == 'P')
				return ;
			info->start_x += 1;
		}
		map = map->next;
		info->start_y += 1;
	}
	return ;
}

char	*dup_map(t_map *map, t_info *info)
{
	char	*map_dfs;
	char	*tmp;
	int		i;

	map_dfs = malloc(info->height * info->width + 1);
	if (!map_dfs)
		put_error_exit("malloc error\n");
	tmp = map_dfs;
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			*tmp = map->line[i];
			tmp++;
			i++;
		}
		map = map->next;
	}
	*tmp = '\0';
	return (map_dfs);
}

void	still_exit_coin(char *map_dfs)
{
	int	i;

	i = 0;
	while (map_dfs[i])
	{
		if (map_dfs[i] == 'E' || map_dfs[i] == 'C')
			put_error_exit("invalid path\n");
		i++;
	}
}

void	check_valid_path(t_map *map, t_info *info)
{
	char	*map_dfs;

	find_start(map, info);
	map_dfs = dup_map(map, info);
	dfs(map_dfs, info->start_x, info->start_y, info);
	still_exit_coin(map_dfs);
	free(map_dfs);
}

void	check_error_map(char *map_name, t_map **map, t_info *info)
{
	check_extention(map_name);
	get_map(map_name, map, info);
	check_width(*map, info);
	check_component(*map, info);
	check_valid_path(*map, info);
}
