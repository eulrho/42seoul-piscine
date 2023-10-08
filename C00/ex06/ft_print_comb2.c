/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:50:40 by erho              #+#    #+#             */
/*   Updated: 2023/08/27 11:51:50 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_result(int a, int b)
{
	char	buff[7];

	buff[0] = a / 10 + 48;
	buff[1] = a % 10 + 48;
	buff[2] = ' ';
	buff[3] = b / 10 + 48;
	buff[4] = b % 10 + 48;
	buff[5] = ',';
	buff[6] = ' ';
	if (a == 98)
	{
		if (b == 99)
			write(1, &buff, 5);
	}
	else
		write(1, &buff, 7);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			print_result(num1, num2);
			num2++;
		}
		num1++;
	}	
}
