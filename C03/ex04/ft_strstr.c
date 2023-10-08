/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:10:27 by erho              #+#    #+#             */
/*   Updated: 2023/09/03 10:27:12 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare(char *str, char *to_find)
{
	while (*to_find)
	{
		if (*str++ != *to_find++)
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*start_addr;
	int		check_result;

	if (*to_find == 0)
		return (str);
	start_addr = 0;
	while (*str)
	{
		check_result = ft_compare(str, to_find);
		if (check_result == 1)
		{
			start_addr = str;
			break ;
		}
		str++;
	}
	return (start_addr);
}
