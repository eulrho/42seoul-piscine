/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:12:01 by erho              #+#    #+#             */
/*   Updated: 2023/09/10 21:13:16 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;
	int		len;

	len = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s;
	int			idx;

	s = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (s == 0)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		s[idx].size = ft_strlen(av[idx]);
		s[idx].str = av[idx];
		s[idx].copy = ft_strdup(av[idx]);
		idx++;
	}
	s[ac].str = 0;
	return (s);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	t_stock_str *s = ft_str_to_tab(ac, av);
	for (int i=0; i<3; i++)
	{
		printf("size: %d\n", s[i].size);
		printf("str: %s\n", s[i].str);
		printf("cpy: %s\n", s[i].copy);
	}
}
*/
