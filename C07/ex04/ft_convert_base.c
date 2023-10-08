/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:23:54 by erho              #+#    #+#             */
/*   Updated: 2023/09/09 18:38:16 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_valid(char *str, int *check_negative);
int	ft_strlen(char *str);
int	ft_conditions_of_termination(char *base);
int	ft_string_to_int(char *str, char *base, int size);
int	get_value(char c, char *base);

int	ft_nbrlen_base(int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		count++;
	while (nbr)
	{
		nbr /= ft_strlen(base);
		count++;
	}
	return (count);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long			n;
	char			*buff;
	int				count;

	count = ft_nbrlen_base(nbr, base);
	buff = (char *)malloc(sizeof(char) * (count + 2));
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		buff[0] = '-';
	}
	if (n == 0)
	{
		buff[0] = base[0];
		buff[1] = '\0';
		return (buff);
	}
	buff[count] = '\0';
	while (n)
	{
		buff[--count] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (buff);
}

void	ft_cpy(char *ret, char *result, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		ret[idx] = result[idx];
		idx++;
	}
	ret[idx] = 0;
}

int	ft_atoi_base(char *str, char *base)
{
	int	check_negative;
	int	nb;
	int	size;

	size = ft_strlen(base);
	str += ft_check_valid(str, &check_negative);
	nb = ft_string_to_int(str, base, size);
	nb *= check_negative;
	return (nb);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_nbr;
	char	*result;
	char	*ret;
	int		len;

	if (ft_conditions_of_termination(base_from) == 0)
		return (0);
	if (ft_conditions_of_termination(base_to) == 0)
		return (0);
	decimal_nbr = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(decimal_nbr, base_to);
	len = ft_strlen(result);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	ft_cpy(ret, result, len);
	free(result);
	return (ret);
}
/*
#include <stdio.h>

int main()
{
	printf("%s\n", ft_convert_base("  +--+-0132 56", "0123456789", "0123456"));
	return (0);
}
*/
