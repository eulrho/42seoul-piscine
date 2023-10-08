/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:23:10 by erho              #+#    #+#             */
/*   Updated: 2023/09/06 14:26:37 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

void	initialize_queens(char *queens, int idx)
{
	queens[idx] = 0;
	if (idx + 1 < 10)
		initialize_queens(queens, idx + 1);
}

int	is_valid(int col_now, int row_now, char *queens)
{
	int	col;

	col = 0;
	if (col_now == 0 && row_now == 0)
		return (1);
	while (col < col_now)
	{
		if (queens[col] == row_now + '0')
			return (0);
		if (ft_abs(col - col_now) == ft_abs(queens[col] - '0' - row_now))
			return (0);
		col++;
	}
	return (1);
}

void	ft_deploy_queens(int line, char *queens, int *cnt)
{
	int	col;
	int	row;

	col = line % 10;
	if (line >= 10)
	{
		write(1, queens, 10);
		write(1, "\n", 1);
		*cnt += 1;
	}
	else
	{
		row = 0;
		while (row < 10)
		{
			if (is_valid(col, row, queens) == 1)
			{
				queens[col] = row + '0';
				ft_deploy_queens(line + 1, queens, cnt);
			}
			row++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	queens[10];
	int		cnt;

	cnt = 0;
	initialize_queens(queens, 0);
	ft_deploy_queens(0, queens, &cnt);
	return (cnt);
}
