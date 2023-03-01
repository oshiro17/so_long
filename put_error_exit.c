/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:10:23 by panti             #+#    #+#             */
/*   Updated: 2023/03/01 22:26:51 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error_exit(char *error_str)
{
	ft_printf("%s", error_str);
	exit(1);
}

int	destroy_win(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}
