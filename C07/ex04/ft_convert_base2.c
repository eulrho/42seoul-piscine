/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:24:06 by erho              #+#    #+#             */
/*   Updated: 2023/09/08 21:24:08 by erho             ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_conditions_of_termination(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_string_to_int(char *str, char *base, int size)
{
	int	nb;
	int	temp;

	nb = 0;
	while (*str && size != 0)
	{
		temp = get_value(*str, base);
		if (temp == -1)
			break ;
		else
			nb = nb * ft_strlen(base) + temp;
		str++;
	}
	return (nb);
}
