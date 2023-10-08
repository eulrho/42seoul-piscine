/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:56:33 by erho              #+#    #+#             */
/*   Updated: 2023/09/03 21:42:41 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_nbrlen(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	insert_buff(char *buff, int nb, int len)
{
	int	i;

	i = len - 1;
	while (nb != 0)
	{
		buff[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	buff[10];
	int		nb_len;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		nb *= -1;
	}
	nb_len = ft_nbrlen(nb);
	insert_buff(buff, nb, nb_len);
	write(1, &buff, nb_len);
}
