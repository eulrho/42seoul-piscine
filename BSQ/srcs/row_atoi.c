/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sewopark <kosuking@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:55 by sewopark          #+#    #+#             */
/*   Updated: 2023/09/14 02:50:43 by sewopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	size;

	size = ft_strlen(str) - 3;
	i = 0;
	res = 0;
	while (i < size)
	{	
		if (str[i] == '+')
		{
			i++;
			continue ;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (res);
}
