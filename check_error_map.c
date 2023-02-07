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

void	check_error_map(char *map_name, t_map **map)
{
	check_extention(map_name);
	get_map(map_name,map);
	
	while((*map)->next)
	{
		ft_printf("%s\n",(*map)->line);
		(*map) = (*map)->next;
	}
}
