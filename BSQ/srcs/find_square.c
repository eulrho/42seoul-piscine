/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:51:15 by erho              #+#    #+#             */
/*   Updated: 2023/09/13 21:48:19 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_math.h"
#include "ft_string.h"
#include "dp.h"

void	initialize_dp(char **map, int **dp, t_map m)
{
	int	idx_row;
	int	idx_col;

	idx_row = 0;
	while (idx_row < m.rows)
	{
		dp[idx_row] = (int *)malloc(m.cols * sizeof(int));
		if (dp[idx_row] == 0)
			return ;
		idx_col = 0;
		while (idx_col < m.cols)
		{
			if (map[idx_row][idx_col] == m.empty)
				dp[idx_row][idx_col] = 1;
			else
				dp[idx_row][idx_col] = 0;
			idx_col++;
		}
		idx_row++;
	}
}

void	draw_square(char **map, t_dp_map result, t_map m)
{
	int	row;
	int	col;

	row = result.max_row;
	while (row > result.max_row - result.max_size)
	{
		col = result.max_col;
		while (col > result.max_col - result.max_size)
		{
			map[row][col] = m.box;
			col--;
		}
		row--;
	}
}

void	find_max_size(int **dp, char **map, t_map m)
{
	int			row;
	int			col;
	t_dp_map	result;

	result.max_size = 0;
	row = -1;
	while (++row < m.rows)
	{
		col = -1;
		while (++col < m.cols)
		{
			if (map[row][col] != m.obstacle)
			{
				dp[row][col] = dp_min(dp, row, col);
				if (result.max_size < dp[row][col])
				{
					result.max_size = dp[row][col];
					result.max_row = row;
					result.max_col = col;
				}
			}
		}
	}
	draw_square(map, result, m);
}

void	find_largest_square(char **map, t_map m)
{
	int	**dp;

	dp = (int **)malloc(m.rows * sizeof(int *));
	if (dp == 0)
		return ;
	initialize_dp(map, dp, m);
	find_max_size(dp, map, m);
}

int	find_square(char **map)
{
	int		idx;
	char	*tail;
	t_map	m;

	idx = 0;
	m.rows = ft_atoi(map[0]);
	tail = map[0] + ft_strlen(map[0]) - 3;
	m.empty = tail[0];
	m.obstacle = tail[1];
	m.box = tail[2];
	map = &map[1];
	m.cols = ft_strlen(map[0]);
	find_largest_square(map, m);
	while (idx < m.rows)
	{
		ft_putstr(map[idx]);
		idx++;
	}
	return (0);
}
