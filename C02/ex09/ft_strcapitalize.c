/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:11:02 by erho              #+#    #+#             */
/*   Updated: 2023/09/01 15:32:44 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	condition_of_header(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (0);
	else if (*str >= 'a' && *str <= 'z')
		return (0);
	else if (*str >= 'A' && *str <= 'Z')
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;
	int		check_header;

	ret = str;
	check_header = 1;
	while (*ret)
	{
		if (check_header == 1)
		{
			if (*ret >= 'a' && *ret <= 'z')
				*ret -= ('a' - 'A');
		}
		else
		{
			if (*ret >= 'A' && *ret <= 'Z')
				*ret += ('a' - 'A');
		}
		check_header = condition_of_header(ret);
		ret++;
	}
	return (str);
}
