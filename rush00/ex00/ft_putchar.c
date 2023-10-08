/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:32:02 by erho              #+#    #+#             */
/*   Updated: 2023/08/27 18:36:38 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int x, char c1, char c2, char c3)
{
	int		width;
	char	buff;

	width = x;
	buff = '\n';
	while (width--)
	{
		if (width == x -1)
			write(1, &c1, 1);
		else if (width == 0)
			write(1, &c3, 1);
		else
			write(1, &c2, 1);
	}
	write(1, &buff, 1);
}
