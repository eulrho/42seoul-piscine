/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:51:00 by erho              #+#    #+#             */
/*   Updated: 2023/09/13 14:28:57 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	dp_min(int **dp, int row, int col)
{
	int	minimum;

	if (row == 0 || col == 0)
		return (1);
	else
	{
		minimum = min(dp[row - 1][col], dp[row - 1][col - 1]);
		minimum = min(minimum, dp[row][col - 1]);
	}
	return (minimum + 1);
}
