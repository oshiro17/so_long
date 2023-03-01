/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:03:42 by noshiro           #+#    #+#             */
/*   Updated: 2023/03/01 22:08:54 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*find_lst_node(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

void	make_list(char *line, t_map **map)
{
	t_map	*last;
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		put_error_exit("malloc error\n");
	new_map->line = line;
	new_map->next = NULL;
	new_map->pre = NULL;
	last = find_lst_node(*map);
	if (!(*map))
	{
		(*map) = new_map;
		return ;
	}	
	else
	{
		last->next = new_map;
		last->next->pre = last;
	}
}

int	open_file(char *map_name)
{
	int	fd;

	fd = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		put_error_exit("open errpr\n");
	return (fd);
}

void	get_map(char *map_name, t_map **map, t_info *info)
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	fd = open_file(map_name);
	i = -1;
	info->height = 0;
	while (line || i == -1)
	{
		line = get_next_line(fd);
		if ((!line || line[0] == '\n' || !line[0]) && i == -1)
			put_error_exit("no contents\n");
		else if (!line)
			break ;
		i = 0;
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		line[i] = '\0';
		make_list(line, map);
		info->height = info->height + 1;
	}
	return ;
}
