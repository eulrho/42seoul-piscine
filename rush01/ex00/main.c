/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <sj7288sj@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:33:57 by seungjun          #+#    #+#             */
/*   Updated: 2023/09/03 15:57:16 by seungjun         ###   ########.fr       */
/*   Updated: 2023/09/03 13:54:45 by seungjun         ###   ########.fr       */
/*   Updated: 2023/09/03 13:49:41 by ji-kang          ###   ########.fr       */
/*   Updated: 2023/09/02 17:19:24 by seungjun         ###   ########.fr       */
/*   Updated: 2023/09/02 17:15:40 by ji-kang          ###   ########.fr       */
/*   Updated: 2023/09/02 15:32:29 by seungjun         ###   ########.fr       */
/*   Updated: 2023/09/02 15:34:25 by ji-kang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	rush01(int **argv, int n);

int	chk_arg(int *arr, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n < arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	ret_arg(char *str, int *arr)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if ('1' <= str[i] && str[i] <= '9' && i % 2 == 0)
			arr[size++] = str[i] - 48;
		else if (((9 <= str[i] && str[i] <= 13) || str[i] == 32) && i % 2 == 1)
			;
		else
			return (0);
		i++;
	}
	if ('1' > str[i - 1] || str[i - 1] > '9')
		return (0);
	return (size);
}

void	allow_arg(int *arr, int n)
{
	int	i;
	int	j;
	int	**argv;

	i = 0;
	argv = (int **) malloc(8 * n);
	while (i < 4)
	{
		argv[i] = (int *) malloc(4 * n);
		j = 0;
		while (j < n)
		{
			argv[i][j] = arr[n * i + j];
			j++;
		}
		i++;
	}
	rush01(argv, n);
	i = 0;
	while (i < n)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	main(int argc, char **argv)
{
	int	n;
	int	size;
	int	arr[1000];

	n = 0;
	size = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	size = ret_arg(argv[1], arr);
	while (n++ < 10)
	{
		if (4 * n == size)
		{
			if (chk_arg(arr, n, size) == 1)
			{
				allow_arg(arr, n);
				return (0);
			}
		}
	}
	write(1, "Error\n", 7);
	return (0);
}
