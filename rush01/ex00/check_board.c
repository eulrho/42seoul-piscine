/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:08:55 by erho              #+#    #+#             */
/*   Updated: 2023/09/03 15:56:30 by seungjun         ###   ########.fr       */
/*   Updated: 2023/09/03 15:42:52 by ji-kang          ###   ########.fr       */
/*   Updated: 2023/09/03 13:26:50 by erho             ###   ########.fr       */
/*   Updated: 2023/09/03 13:12:44 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	up(int **array, int n, int *result)
{
	int	row;
	int	col;
	int	top;
	int	cnt;

	col = 0;
	while (col < n)
	{
		cnt = 0;
		row = 0;
		top = 0;
		while (row < n)
		{
			if (array[row][col] > top)
			{
				top = array[row][col];
				cnt++;
			}
			row++;
		}
		*result = cnt;
		result++;
		col++;
	}
}

void	down(int **array, int n, int *result)
{
	int	row;
	int	col;
	int	top;
	int	cnt;

	col = 0;
	while (col < n)
	{
		cnt = 0;
		row = 0;
		top = 0;
		while (row < n)
		{
			if (array[n - row - 1][col] > top)
			{
				top = array[n - row - 1][col];
				cnt++;
			}
			row++;
		}
		*result = cnt;
		result++;
		col++;
	}
}

void	left(int **array, int n, int *result)
{
	int	row;
	int	col;
	int	top;
	int	cnt;

	row = 0;
	while (row < n)
	{
		cnt = 0;
		col = 0;
		top = 0;
		while (col < n)
		{
			if (array[row][col] > top)
			{
				top = array[row][col];
				cnt++;
			}
			col++;
		}
		*result = cnt;
		result++;
		row++;
	}
}

void	right(int **array, int n, int *result)
{
	int	row;
	int	col;
	int	top;
	int	cnt;

	row = 0;
	while (row < n)
	{
		cnt = 0;
		col = 0;
		top = 0;
		while (col < n)
		{
			if (array[row][n - col - 1] > top)
			{
				top = array[row][n - col - 1];
				cnt++;
			}
			col++;
		}
		*result = cnt;
		result++;
		row++;
	}
}

int	check_board(int **array, int **argv, int n)
{
	int	*result;
	int	i;

	i = -1;
	while (++i < n * n)
	{
		if (array[i / n][i % n] == 0)
			return (0);
	}
	result = (int *)malloc(4 * n * 4);
	up(array, n, result);
	down(array, n, result + n);
	left(array, n, result + n * 2);
	right(array, n, result + n * 3);
	i = -1;
	while (++i < n * 4)
	{	
		if (result[i] != argv[i / n][i % n])
		{
			free(result);
			return (0);
		}
	}
	free(result);
	return (1);
}
