# include "so_long.h"

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
	t_map *last;
	t_map *new_map;


	new_map = malloc(sizeof(t_map));
	if (!new_map)
		put_error_exit("sorry,malloc error");
	new_map->line = line;
	new_map->next = NULL;
	new_map->pre = NULL;
	if (!(*map)->line)
	{
		(*map) = new_map;
		return ;
	}
	last = find_lst_node(*map);
	last->next = new_map;
	last->next->pre = last;
}

void get_map(char *map_name, t_map **map)
{
	char	*line;
	int		fd;
	int		i;
	// size_t		line_len;

	// line_len = 0;
	line = NULL;
	fd = open(map_name, O_RDONLY);
	i = -1;
	while (line || i == -1)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		line[i] = '\0';
		make_list(line,map);
		// if (line_len != 0 || line_len != ft_strlen(line))
		// 	put_error_exit("not rectangle");
		// line_len = ft_strlen(line);
	}
	return ;
	// t_map *test;
	// test = map;
	// while (test->next)
	// {
	// 	printf("%s\n",test->line);
	// 	test = test->next;
	// }
}