/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:52:32 by erho              #+#    #+#             */
/*   Updated: 2023/09/07 11:36:36 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_valid(char *str, int *check_negative)
{
	int	count;

	count = 0;
	*check_negative = 1;
	while (*str && ((*str >= '\t' && *str <= '\r') || *str == ' '))
	{
		str++;
		count++;
	}
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			*check_negative *= -1;
		str++;
		count++;
	}
	return (count);
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
	int	size;

	size = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	if (ft_overlap(base) == 0)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		if ((*base >= '\t' && *base <= '\r') || *base == ' ')
			return (0);
		base++;
		size++;
	}
	return (size);
}

int	ft_string_to_int(char *str, char *base, int size)
{
	int	nb;
	int	idx;
	int	temp;

	nb = 0;
	while (*str && size != 0)
	{
		idx = 0;
		temp = nb;
		while (base[idx])
		{
			if (*str == base[idx])
				nb = nb * size + idx;
			idx++;
		}
		if (temp == nb)
			break ;
		str++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	check_negative;
	int	nb;
	int	size;

	size = ft_conditions_of_termination(base);
	str += ft_check_valid(str, &check_negative);
	nb = ft_string_to_int(str, base, size);
	nb *= check_negative;
	return (nb);
}

#include <stdio.h>

int main()
{
	printf("%d", ft_atoi_base("12", "0123456789abcdef"));
}