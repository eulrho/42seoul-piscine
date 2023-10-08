/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:49 by erho              #+#    #+#             */
/*   Updated: 2023/09/09 18:35:50 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *sep)
{
	int	i;

	i = 0;
	while (*sep)
	{
		i++;
		sep++;
	}
	return (i);
}

int	ft_total_len(char size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			cnt++;
			j++;
		}
		if (i != size -1)
			cnt += ft_strlen(sep);
		i++;
	}
	return (cnt);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;
	int		dest_len;

	ret = dest;
	dest_len = ft_strlen(ret);
	dest += dest_len;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}

void	ft_join(char *temp, int size, char *sep, char **strs)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		temp = ft_strcat(temp, strs[idx]);
		if (idx != size - 1)
			temp = ft_strcat(temp, sep);
		idx++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*temp;
	int		len;
	int		idx;

	if (size == 0)
	{
		temp = (char *)malloc(1);
		*temp = 0;
		return (temp);
	}
	len = ft_total_len(size, strs, sep);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	idx = 0;
	while (idx < len + 1)
		temp[idx++] = 0;
	ft_join(temp, size, sep, strs);
	return (temp);
}
/*
#include <stdio.h>
int main()
{
	int size = 3;
	char **strs;
	char *sep = ", ";
	int idx;
	char *join;

	strs = (char **)malloc(size);
	idx = 0;
	while (idx < size)
		strs[idx++] = (char *)malloc(10);
	strs[0] = "hello";
	strs[1] = "word";
	strs[2] = "yeah\n";
	join = ft_strjoin(size, strs, sep);
	printf("%s", join);
}*/
