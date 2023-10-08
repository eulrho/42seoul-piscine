/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:57:21 by erho              #+#    #+#             */
/*   Updated: 2023/09/11 19:41:52 by erho             ###   ########.fr       */
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

	str += ft_check_valid(str, &check_negative);
	nb = ft_number(str);
	nb *= check_negative;
	return (nb);
}
