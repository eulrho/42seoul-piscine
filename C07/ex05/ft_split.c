/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:34:05 by erho              #+#    #+#             */
/*   Updated: 2023/09/14 14:26:38 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_charset(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_insert_word(char *ret, char *str, int idx, int size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		ret[i++] = str[idx - size];
		size--;
	}
	ret[i] = 0;
	return (0);
}

void	ft_get_words(char **ret, char *str, char *charset, int idx)
{
	int	flag;
	int	cnt;
	int	ret_idx;

	flag = 1;
	cnt = 0;
	ret_idx = 0;
	while (str[idx])
	{
		if (ft_check_charset(str[idx], charset) == 1)
		{
			if (flag == 0)
				cnt = ft_insert_word(ret[ret_idx++], str, idx, cnt);
			flag = 1;
		}
		else
		{	
			flag = 0;
			cnt++;
		}
		idx++;
	}
	if (ft_check_charset(str[idx - 1], charset) == 0)
		ft_insert_word(ret[ret_idx], str, idx, cnt);
}

int	ft_count_words(char *str, char *charset)
{
	int	idx;
	int	flag;
	int	cnt;

	idx = 0;
	flag = 1;
	cnt = 0;
	while (str[idx])
	{
		if (ft_check_charset(str[idx], charset) == 1)
			flag = 1;
		else
		{
			if (flag == 1)
				cnt++;
			flag = 0;
		}
		idx++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		size;
	int		len;
	int		idx;

	len = 0;
	while (str[len])
		len++;
	size = ft_count_words(str, charset);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	idx = 0;
	while (idx < size)
		ret[idx++] = (char *)malloc(sizeof(char) * (len + 1));
	idx = 0;
	ft_get_words(ret, str, charset, idx);
	ret[size] = 0;
	return (ret);
}
#include <stdio.h>
int main()
{
	char **res = ft_split("            ", "   ");
	int idx = 0;
	while (res[idx])
	{
		printf("%s:\n", res[idx]);
		idx++;
	}
	return (0);
}
