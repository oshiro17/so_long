/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:14:30 by noshiro           #+#    #+#             */
/*   Updated: 2023/02/04 06:53:03 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	c = 0;
	while (s1 && s1[i] != '\0')
		str[i++] = s1[c++];
	c = 0;
	while (s2 && s2[c] != '\0')
		str[i++] = s2[c++];
	str[gnl_ft_strlen(s1) + gnl_ft_strlen(s2)] = '\0';
	free_null(&s1);
	return (str);
}

char	*gnl_ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}