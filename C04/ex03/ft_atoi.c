/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:36:04 by erho              #+#    #+#             */
/*   Updated: 2023/09/03 21:47:04 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_blank(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if ((*str >= '\t' && *str <= '\r') || *str == ' ')
		{
			str++;
			count++;
			continue ;
		}
		else
			break ;
	}
	return (count);
}

int	ft_check_negative(char *str, int *check_negative)
{
	int	count;

	count = 0;
	*check_negative = 0;
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				(*check_negative)++;
			str++;
			count++;
		}
		else
			break ;
	}
	return (count);
}

int	ft_number(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nb = nb * 10 + (*str - '0');
		else
			break ;
		str++;
	}
	return (nb);
}

int	ft_atoi(char *str)
{
	int	check_negative;
	int	nb;
	int	len;

	check_negative = 0;
	len = ft_blank(str);
	len += ft_check_negative(str + len, &check_negative);
	nb = ft_number(str + len);
	if (check_negative % 2 == 1)
		nb *= -1;
	return (nb);
}
