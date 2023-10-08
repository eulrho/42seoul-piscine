/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:06:20 by erho              #+#    #+#             */
/*   Updated: 2023/09/04 22:28:43 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_buff(char *base, unsigned int n, int base_nb)
{
	char	buff[33];
	int		count;

	count = 0;
	while (n)
	{
		buff[count] = base[n % base_nb];
		n /= base_nb;
		count++;
	}
	while (--count >= 0)
	{
		write(1, &buff[count], 1);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_overlap(char *str)
{
	int	idx_i;
	int	idx_j;

	idx_i = 0;
	while (str[idx_i])
	{
		idx_j = idx_i + 1;
		while (str[idx_j])
		{
			if (str[idx_i] == str[idx_j])
				return (0);
			idx_j++;
		}
		idx_i++;
	}
	return (1);
}

int	ft_conditions_of_termination(char *base)
{
	if (ft_strlen(base) <= 1)
		return (0);
	if (ft_overlap(base) == 0)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_nb;
	unsigned int	n;

	if (ft_conditions_of_termination(base) == 0)
		return ;
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	else if (nbr < 0)
	{
		n = (unsigned int)(nbr * -1);
		write(1, "-", 1);
	}
	else
		n = (unsigned int)nbr;
	base_nb = ft_strlen(base);
	ft_buff(base, n, base_nb);
}
