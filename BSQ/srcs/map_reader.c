/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:18:01 by erho              #+#    #+#             */
/*   Updated: 2023/09/14 04:01:00 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h> // open
#include <unistd.h> // write, read
#include <stdlib.h>
#include "dp.h"
#include "ft_valid.h"
#include <stdio.h>

#define BUFF_SIZE 1024

char	**make_name_arr(char *buff, ssize_t nread);

char	*insert_buff(char *buff, int nbr_read)
{
	char	*res;
	int		idx;

	idx = 0;
	res = (char *)malloc(sizeof(char) * (nbr_read + 1));
	if (res == 0)
		return (0);
	while (idx < nbr_read)
	{
		res[idx] = buff[idx];
		idx++;
	}
	res[idx] = 0;
	return (res);
}

int	read_map(char *argv)
{
	char	**map;
	char	buff[BUFF_SIZE];
	int		fd;
	char	*res;
	int		nbr_read;

	fd = open(argv, O_RDONLY);
	if (0 < fd)
		nbr_read = read(fd, buff, BUFF_SIZE);
	else
	{
		write(2, "invalid\n", 8);
		return (0);
	}
	res = insert_buff(buff, nbr_read);
	map = create_map(res);
	if (is_valid(map) == -1 || is_same_condition(map) == -1)
	{
		write(2, "invalid\n", 8);
		return (0);
	}
	find_square(map);
	free(res);
	close(fd);
	return (0);
}

char	*make_name(char *start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len +1);
	while (i < len)
	{
		str[i] = start[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_name(char *buff, ssize_t nread)
{
	char	*line_start;
	int		i;
	char	**names;
	int		j;

	line_start = buff;
	i = -1;
	while (++i < nread)
	{
		if (buff[i] == '\n')
		{
			names = make_name_arr(line_start, &buff[i] - line_start);
			j = 0;
			while (names[j])
			{
				read_map(names[j]);
				write(1, "\n", 1);
				j++;
			}
		}
	}
}

void	ft_stdin(void)
{
	char	buff[BUFF_SIZE];
	ssize_t	nread;

	while (1)
	{
		nread = read(STDIN_FILENO, buff, BUFF_SIZE);
		if (nread == 1)
			continue ;
		else
		{
			ft_name(buff, nread);
			break ;
		}
	}
}
