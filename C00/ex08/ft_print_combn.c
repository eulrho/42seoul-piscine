/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:58:07 by erho              #+#    #+#             */
/*   Updated: 2023/08/26 18:39:51 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_insert(char *buff, int idx, int n, char num)
{
	buff[idx] = num;
	if (idx != n - 1)
		repeat_insert(buff, idx + 1, n, num + 1);
	else
	{
		if (buff[0] == '9' - n + 1)
			write (1, buff, n);
		else
			write (1, buff, n + 2);
	}
	num++;
	if (num <= '9' - n + idx + 1)
		repeat_insert(buff, idx, n, num);
}

void	ft_print_combn(int n)
{
	char	buff[11];
	char	num;
	int		idx;

	idx = 0;
	num = '0';
	buff[n] = ',';
	buff[n + 1] = ' ';
	repeat_insert(buff, idx, n, num);
}
