/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:04:20 by noshiro           #+#    #+#             */
/*   Updated: 2023/03/01 21:38:55 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *line, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->width)
	{
		if ((i == 0 || i == info->width - 1) && line[i] != '1')
			put_error_exit("not surrounded by 1\n");
		else if (line[i] == 'C')
			info->c_num = info->c_num + 1;
		else if (line[i] == 'E')
			info->e_num = info->e_num + 1;
		else if (line[i] == 'P')
			info->p_num = info->p_num + 1;
		else if (line[i] == '0')
			info->zero_num = info->zero_num + 1;
		else if (line[i] == '1')
			info->one_num = info ->one_num + 1;
		else
			put_error_exit("map component error\n");
		i++;
	}
}

void	check_all_one(char *line, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		if (line[i] != '1')
			put_error_exit("not surrounded by 1\n");
		i++;
	}
	info->one_num = info->one_num + info->width;
}

void	check_component(t_map *map, t_info *info)
{
	int	height;

	height = info->height - 2;
	check_all_one(map->line, info);
	map = map->next;
	while (height--)
	{
		check_line(map->line, info);
		map = map->next;
	}
	check_all_one(map->line, info);
	if (info->e_num != 1 || info->c_num < 1 || info->p_num != 1)
		put_error_exit("map component error\n");
}
