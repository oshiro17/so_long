/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:48:10 by panti             #+#    #+#             */
/*   Updated: 2023/02/04 06:40:19 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int argc, char **argv)
{
	if (argc < 2)
		put_error_exit("no map.");
	if (argc > 2)
		put_error_exit("too many arguments");
	return(0);
}