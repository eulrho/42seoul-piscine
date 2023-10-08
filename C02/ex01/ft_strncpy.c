/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:38:12 by erho              #+#    #+#             */
/*   Updated: 2023/08/30 18:38:12 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = dest;
	while (i < n)
	{
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = '\0';
		i++;
	}
	return (ret);
}
