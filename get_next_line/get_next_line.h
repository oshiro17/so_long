/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:26:25 by noshiro           #+#    #+#             */
/*   Updated: 2023/02/04 06:40:03 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libc.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*free_null(char **line);

#endif