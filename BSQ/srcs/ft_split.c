/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:37:19 by sewopark          #+#    #+#             */
/*   Updated: 2023/09/14 03:59:52 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*make_word(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

int	count_word(char *str)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		flag = i;
		while (str[i] && str[i] == '\n')
			i++;
		if (flag - i > 1)
			return (-1);
		if (str[i])
			cnt++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (cnt);
}

int	ft_insert(char *str, char **res)
{
	int	i;
	int	word;
	int	array;

	i = 0;
	array = 0;
	word = 0;
	while (str[i])
	{	
		while (str[i] && str[i] == '\n')
			i++;
		word = i;
		while (str[i] && str[i] != '\n')
			i++;
		if (i > word)
		{
			res[array] = (char *)malloc(sizeof(char) * ((i - word) + 1));
			if (res[array] == 0)
				return (0);
			make_word(res[array], &str[word], i - word);
			array++;
		}
	}
	return (array);
}

char	**ft_split(char *str)
{
	int		array;
	int		cnt;
	char	**res;

	cnt = count_word(str);
	if (cnt == -1)
	{
		res = (char **)malloc(1);
		res[0] = 0;
		return (res);
	}
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (res == 0)
		return (0);
	array = ft_insert(str, res);
	res[array] = 0;
	return (res);
}
