/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:31:01 by erho              #+#    #+#             */
/*   Updated: 2023/08/31 21:03:31 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;
	int		dest_len;
	int		i;

	ret = dest;
	i = 0;
	dest_len = ft_strlen(dest);
	dest += dest_len;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}
