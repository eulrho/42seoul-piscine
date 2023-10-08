/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:53:08 by erho              #+#    #+#             */
/*   Updated: 2023/09/11 18:53:38 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_nbrlen(int nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	insert_buff(int i, char *buff, int len_nb, int nb)
{
	buff[len_nb - i] = nb % 10 + '0';
	nb /= 10;
	if (nb != 0)
		insert_buff(i + 1, buff, len_nb, nb);
}

void	ft_putnbr(int nb)
{
	char	buff[10];
	int		i;

	i = 1;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		else
		{
			write(1, "-", 1);
			nb *= -1;
		}
	}
	insert_buff(i, buff, ft_nbrlen(nb), nb);
	write(1, &buff, ft_nbrlen(nb));
}
