/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:22:15 by erho              #+#    #+#             */
/*   Updated: 2023/09/11 18:27:11 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	i = 0;
	up = 0;
	down = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			up = 1;
		else if (f(tab[i], tab[i +1]) > 0)
			down = 1;
		if (up == 1 && down == 1)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	ft_cmp(int str1, int str2)
{
	if (str1 > str2)
		return (1);
	else if (str1 < str2)
		return (-1);
	else
		return (0);
}
int	main()
{
	int	arr1[] = {4, 5, 6, 7, 8, 9, 11, 3};
	int	arr2[] = {1, 2, 3, 8, 8, 8, 11, 22};
	int	arr3[] = {9, 8, 6, 5, 4, 3, 2, 1};

	printf("%d\n", ft_is_sort(arr1, 8, ft_cmp));
	printf("%d\n", ft_is_sort(arr2, 8, ft_cmp));
	printf("%d\n", ft_is_sort(arr3, 8, ft_cmp));
}*/