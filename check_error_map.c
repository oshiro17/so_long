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
		if (map_name[i + k] == extention[k])
			k++;
		else
			put_error_exit("extention is not .ber");
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
	if (info->width < 5)
		put_error_exit("width < 5");
}

void check_line(char *line, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->width)
	{
		if ((i == 0 || i == info->width - 1) && line[i] != '1')
			put_error_exit("not surrounded by 1");
		else if (line[i] == 'C')
			info->c_num = info->c_num + 1;
		else if(line[i] == 'E')
			info->e_num = info->e_num + 1;
		else if(line[i] == 'P')
			info->p_num = info->p_num + 1;
		else if(line[i] == '0')
			info->zero_num = info->zero_num + 1;
		else if(line[i] == '1')
			info->one_num = info ->one_num + 1;
		else
			put_error_exit("map component error");
		i++;
	}
}

void	check_all_one(char *line,t_info *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		if (line[i] != '1')
			put_error_exit("not surrounded by 1");
		i++;
	}
	info->one_num = info->one_num + info->width;
}

void	check_component(t_map *map, t_info *info)
{
	int height;

	height = info->height - 2;
	check_all_one(map->line, info);
	map = map->next;
	while (height--)
	{
		check_line(map->line, info);
		map = map->next;
	}
	check_all_one(map->line, info);
	if (info->e_num != 1 || info->c_num < 1 ||info->p_num != 1)
	put_error_exit("map component error");
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

bool	is_not_one(char *map_dfs, int x, int y, t_info *info)
{
	if (map_dfs[y * info->width + x] != '1')
		return (true);
	return (false);
}

bool is_e(char *map_dfs, int x, int y, t_info *info)
{
	if (map_dfs[y * info->width + x] == 'E')
		return (true);
	return (false);	
}

void	dfs(char *map_dfs, int x, int y, t_info *info)
{
	printf("%s\n",map_dfs);
	map_dfs[y * info->width + x] = '1';
	if (is_not_one(map_dfs, x + 1, y, info))
	{
		if (is_e(map_dfs, x + 1, y, info))
		{	
			map_dfs[y * info->width + x + 1] = '1';
			dfs(map_dfs, x, y, info);
		}
		else
			dfs(map_dfs, x + 1, y, info);
	}
	if (is_not_one(map_dfs, x - 1, y, info))
	{
		if (is_e(map_dfs, x - 1, y, info))
		{	
			map_dfs[y * info->width + x - 1] = '1';
			dfs(map_dfs, x, y, info);
		}
		else
			dfs(map_dfs, x - 1, y, info);
	}
	if (is_not_one(map_dfs, x, y + 1, info))
	{
		if (is_e(map_dfs, x, y + 1, info))
		{	
			map_dfs[y * info->width + x + 1] = '1';
			dfs(map_dfs, x, y, info);
		}	
		else
			dfs(map_dfs, x, y + 1, info);
	}
	if (is_not_one(map_dfs, x + 1, y, info))
	{
		if (is_e(map_dfs, x + 1, y, info))
		{	
			map_dfs[y * info->width + x + 1] = '1';
			dfs(map_dfs, x, y, info);
		}	
		else
			dfs(map_dfs, x, y - 1, info);
	}
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
	// check_width(*map,info);
	// check_component(*map,info);
	// check_valid_path(*map, info);
}
