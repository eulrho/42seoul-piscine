/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:54:27 by erho              #+#    #+#             */
/*   Updated: 2023/08/31 10:08:21 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hex(char *hex, unsigned char c)
{
	unsigned int	rest;
	int				i;

	i = 1;
	while (c != 0)
	{
		rest = c % 16;
		if (rest < 10)
			hex[i] = rest + '0';
		else
			hex[i] = rest + ('a' - 10);
		c /= 16;
		i--;
	}
	while (i >= 0)
		hex[i--] = '0';
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[2];

	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\", 1);
			ft_hex(hex, *str);
			write(1, hex, 2);
		}
		else
			write(1, str, 1);
		str++;
	}
}
