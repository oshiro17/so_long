# include "so_long.h"

void	check_extention(char *map_name)
{
	int			i;
	int			k;
	const char	*extention = ".ber";

	i = 0;
	k = 0;
	while (map_name[i] && map_name[i] != '.')
		i++;
	if (map_name[i - 1] == '/' || i == 0)
		put_error_exit("map name error");
	while (map_name[i + k])
	{
		if (map_name[i + k] != extention[k])
			put_error_exit("extention is not .ber");
		k++;
		if (map_name[i + k] == '.' && k == 4)
		{
			i = k + i;
			k = 0;
		}
	}
	if (k != 4)
		put_error_exit("extention is not .ber");
}

void	check_width(t_map *map, t_info *info)
{
	int height;

	height = info->height;
	info->width = (int)ft_strlen(map->line);
	while(height--)
	{
		if(info->width != (int)ft_strlen(map->line))
			put_error_exit("not ractangle");
		map = map->next;
	}
}

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
	get_map(map_name,map,info);
	check_width(*map,info);
	check_component(*map,info);
	check_valid_path(*map, info);
}
