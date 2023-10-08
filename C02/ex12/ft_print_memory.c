/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:56:14 by erho              #+#    #+#             */
/*   Updated: 2023/09/01 16:23:53 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hex(unsigned long long n, unsigned int size)
{
	int		rest;
	int		i;
	char	hex[16];

	i = size - 1;
	while (n != 0)
	{
		rest = n % 16;
		if (rest < 10)
			hex[i] = rest + '0';
		else
			hex[i] = rest + ('a' - 10);
		n /= 16;
		i--;
	}
	while (i >= 0)
		hex[i--] = '0';
	write(1, &hex, size);
}

void	ft_print_character(unsigned char *ret, unsigned int print_size)
{
	unsigned int	count;

	count = 1;
	while (*ret && count++ <= print_size)
	{
		if (*ret < 32 || *ret > 126)
			write(1, ".", 1);
		else
			write(1, ret, 1);
		ret++;
	}
	write(1, "\n", 1);
}

void	ft_print_character_hex(unsigned char *ret, unsigned int print_size)
{
	unsigned int	count;

	count = 1;
	while (count <= 16)
	{
		if (count <= print_size && *ret)
		{
			ft_hex((unsigned long long)*ret, 2);
			ret++;
		}
		else
			write(1, "  ", 2);
		if (count++ % 2 == 0)
			write(1, " ", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char		*ret;
	unsigned long long	front;
	unsigned int		print_size;

	ret = (unsigned char *)addr;
	while (*ret && size)
	{
		if (size >= 16)
			print_size = 16;
		else
			print_size = size;
		front = (unsigned long long)ret;
		ft_hex(front, 16);
		write(1, ": ", 2);
		ft_print_character_hex(ret, print_size);
		ft_print_character(ret, print_size);
		ret += 16;
		size -= print_size;
	}
	return (addr);
}
