/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <sj7288sj@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:33:19 by seungjun          #+#    #+#             */
/*   Updated: 2023/09/03 15:56:28 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initial_board(int **array, int **argv, int n)
{
	int		row;
	int		col;
	char	c;

	c = argv[0][0] + '0';
	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			array[row][col] = 0;
			col++;
		}
		row++;
	}
}
