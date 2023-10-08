/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:06:47 by erho              #+#    #+#             */
/*   Updated: 2023/08/29 10:48:32 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*ret;

	ret = str;
	while (*ret)
	{
		if (*ret >= 'A' && *ret <= 'Z')
			*ret += ('a' - 'A');
		ret++;
	}
	return (str);
}
