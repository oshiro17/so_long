# include "so_long.h"

void	check_extention(char *map)
{
	int			i;
	int			k;
	const char	*extention = ".xpm";

	i = 0;
	k = 0;
	while (map[i] && map[i] != '.')
		i++;
	while (map[i + k])
	{
		if (map[i + k] == extention[k])
			k++;
		else
			put_error_exit("extention is not .xpm");
	}
	if (k != 4)
		put_error_exit("extention is not .xpm");
}

void	check_error_map(char *map)
{
	int fd;

	check_extention(map);
	fd = open(map,O_RDONLY)
}
