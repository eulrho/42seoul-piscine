/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <sj7288sj@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:05:41 by seungjun          #+#    #+#             */
/*   Updated: 2023/09/03 15:56:36 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_board(int **array, int **argv, int max);

int	is_valid(int **array, int row, int col, int num)
{
	int	cnt;

	if (row == 0 && col == 0 && num == 1)
		return (1);
	else if (row == 0 && array[row][col] != 0)
		return (0);
	else
	{
		cnt = 0;
		while (cnt < row)
		{
			if (array[cnt][col] == num)
				return (0);
			cnt++;
		}
		if (array[row][col] != 0)
			return (0);
	}
	return (1);
}

int	print_board(int **array, int max)
{
	char	c;
	int		row;
	int		col;

	row = 0;
	while (row < max)
	{
		col = 0;
		while (col < max)
		{
			c = array[row][col] + '0';
			write(1, &c, 1);
			if (col + 1 < max)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
	return (1);
}

void	refresh_board(int **array, int num, int row_now, int max)
{
	int	row;
	int	col;

	row = 0;
	while (row < max)
	{
		col = 0;
		while (col < max)
		{
			if (array[row][col] > num)
				array[row][col] = 0;
			else if (array[row][col] == num && row >= row_now)
				array[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	insert_board(int **array, int **argv, int line, int max)
{
	int	col;
	int	result;

	result = 0;
	if (line >= (max * max - 1) && check_board(array, argv, max))
	{
		print_board(array, max);
		return (1);
	}
	else
	{
		col = 0;
		while (col < max)
		{
			refresh_board(array, (line / max) + 1, (line % max), max);
			if (is_valid(array, line % max, col, line / max + 1) && result == 0)
			{
				array[line % max][col] = (line / max) + 1;
				result += insert_board(array, argv, line + 1, max);
			}
			col++;
		}
	}
	return (result);
}
