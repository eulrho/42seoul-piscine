/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:32:36 by erho              #+#    #+#             */
/*   Updated: 2023/08/27 18:32:40 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int x, char c1, char c2, char c3);

void	rush(int x, int y)
{
	int		length;
    
    if (x == -2 || y == -2)
    {
        write(1, "Input value must be number\n", 27);
        return ;
    }
	length = y;
	while (length--)
	{
		if (length == y -1)
			ft_putchar(x, 'o', '-', 'o');
		else if (length == 0)
			ft_putchar(x, 'o', '-', 'o');
		else
			ft_putchar(x, '|', ' ', '|');
	}
}
