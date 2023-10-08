/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <sj7288sj@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:05:41 by seungjun          #+#    #+#             */
/*   Updated: 2023/09/03 15:56:24 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	initial_board(int **array, int **argv, int n);

int		insert_board(int **array, int **argv, int line, int n);

int		is_valid(int **array, int row, int col, int num);

void	rush01(int **argv, int n)
{
	int	**array;
	int	i;
	int	result;

	i = 0;
	result = 0;
	array = (int **)malloc(8 * n);
	while (i < n)
	{
		array[i] = (int *)malloc(4 * n);
		i++;
	}
	initial_board(array, argv, n);
	if (is_valid(array, n - 1, n - 1, n))
		result = insert_board(array, argv, 0, n);
	if (result == 0)
		write(1, "Error\n", 7);
	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
