/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:21:01 by sewopark          #+#    #+#             */
/*   Updated: 2023/09/14 04:06:26 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h> // open
#include <unistd.h> // write, read

char	*insert_buff(char *buff, int nbr_read);
int		read_map(char *argv);
char	*make_name(char *start, int len);
void	ft_name(char *buff, ssize_t nread);
void	ft_stdin(void);
char	*make_word(char *s1, char *s2, int n);

int	arr_insert(char *buff, char **res, int len)
{
	int	i;
	int	word;
	int	array;

	i = 0;
	array = 0;
	word = 0;
	while (i < len)
	{	
		while (buff[i] == ' ' || (buff[i] >= '\t' && buff[i] <= '\r'))
			i++;
		word = i;
		while (!(buff[i] == ' ' || (buff[i] >= '\t' && buff[i] <= '\r')))
			i++;
		if (i > word)
		{
			res[array] = (char *)malloc(sizeof(char) * ((i - word) + 1));
			if (res[array] == 0)
				return (0);
			make_word(res[array], &buff[word], i - word);
			array++;
		}
	}
	return (array);
}

char	**make_name_arr(char *buff, ssize_t nread)
{
	int		cnt;
	char	**res;
	int		i;

	cnt = 0;
	i = 0;
	while (i < nread)
	{
		while (buff[i] == ' ' || (buff[i] >= '\t' && buff[i] <= '\r'))
			i++;
		cnt++;
		while (!(buff[i] == ' ' || (buff[i] >= '\t' && buff[i] <= '\r')))
			i++;
	}
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	res[arr_insert(buff, res, nread)] = 0;
	return (res);
}

int	main(int argc, char **argv)
{
	int	idx;

	idx = 1;
	if (argc == 1)
		ft_stdin();
	while (idx < argc)
	{
		read_map(argv[idx]);
		if (idx != argc -1)
			write(1, "\n", 1);
		idx++;
	}
	idx = 0;
	return (0);
}
