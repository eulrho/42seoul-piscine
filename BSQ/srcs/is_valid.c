/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:42:04 by sewopark          #+#    #+#             */
/*   Updated: 2023/09/14 04:00:28 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	is_double(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (len == i)
		return (1);
	return (0);
}

int	is_valid_printable(char *str)
{
	int		len;
	int		i;
	char	*tail;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] >= 32 && str[i] <= 126)
			i++;
		else
			return (0);
	}
	tail = str + len - 3;
	if (is_double(tail))
		return (1);
	return (0);
}

int	is_num(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '0')
		return (0);
	while (i < ft_strlen(line) - 3)
	{	
		if (line[i] == '+')
			i++;
		else if (!(line[i] >= '0' && line[i] <= '9'))
			return (0);
		else
			i++;
	}
	return (1);
}

int	is_include(char **map, char *tail)
{
	char	empty;
	char	obstacle;
	int		i;
	int		j;

	empty = tail[0];
	obstacle = tail[1];
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != empty && map[i][j] != obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(char **map)
{
	char	*line;
	char	*tail;

	line = map[0];
	tail = line + ft_strlen(map[0]) - 3;
	if (line == 0)
		return (-1);
	if (!(is_valid_printable(line) && is_num(line) && is_include(map, tail)))
		return (-1);
	return (0);
}
