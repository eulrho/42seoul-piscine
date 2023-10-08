/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:26:12 by erho              #+#    #+#             */
/*   Updated: 2023/09/11 21:26:13 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	ft_strlen(char *argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		i++;
		argv++;
	}
	return (i);
}

void	ft_sort(char **tab, int size, int (*cmp)(char *, char *))
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
			ft_str_swap(&tab[i], &tab[i + 1]);
		i++;
	}
	size--;
	if (size > 1)
		ft_sort(tab, size, cmp);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	ft_sort(tab, size, cmp);
}
/*
int	ft_cmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 > *str2)
			return (1);
		else if (*str1 < *str2)
			return (0);
		str1++;
		str2++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{
	char	*arr[20] = {"dsbkb", "ahwuue", "opopckl", "387877", "SEOWOON"};
	ft_advanced_sort_string_tab(arr, ft_cmp);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", arr[i]);
	}
}*/