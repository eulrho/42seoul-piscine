/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:24:01 by erho              #+#    #+#             */
/*   Updated: 2023/09/06 16:09:03 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_sort_params(char *argv[], int size)
{
	int	i;

	i = 1;
	while (i < size - 1)
	{
		if (ft_cmp(argv[i], argv[i + 1]) == 1)
			ft_str_swap(&argv[i], &argv[i + 1]);
		i++;
	}
	size--;
	if (size > 2)
		ft_sort_params(argv, size);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		return (0);
	ft_sort_params(argv, argc);
	i = 1;
	while (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
