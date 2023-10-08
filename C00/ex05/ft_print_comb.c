/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:26:43 by erho              #+#    #+#             */
/*   Updated: 2023/08/26 12:25:55 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_result(char a, char b, char c)
{
	char	buff[5];

	buff[0] = a;
	buff[1] = b;
	buff[2] = c;
	buff[3] = ',';
	buff[4] = ' ';
	if (a == '7' && b == '8' && c == '9')
		write(1, &buff, 3);
	else
		write(1, &buff, 5);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_result(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
