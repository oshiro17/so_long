/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:40:24 by noshiro           #+#    #+#             */
/*   Updated: 2023/03/01 21:42:31 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		put_error_exit("map name error\n");
	while (map_name[i + k])
	{
		if (map_name[i + k] != extention[k])
			put_error_exit("extention is not .ber\n");
		k++;
		if (map_name[i + k] == '.' && k == 4)
		{
			i = k + i;
			k = 0;
		}
	}
	if (k != 4)
		put_error_exit("extention is not .ber\n");
}

void	check_width(t_map *map, t_info *info)
{
	int	height;

	height = info->height;
	info->width = (int)ft_strlen(map->line);
	while (height--)
	{
		if (info->width != (int)ft_strlen(map->line))
			put_error_exit("not ractangle\n");
		map = map->next;
	}
}
