/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:28:48 by erho              #+#    #+#             */
/*   Updated: 2023/09/14 04:05:12 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

int	is_same_condition(char **str)
{
	int	i;
	int	cnt;
	int	len;
	int	size;

	i = 1;
	cnt = 0;
	len = ft_strlen(str[1]);
	size = ft_atoi(str[0]);
	while (str[i])
	{
		cnt = ft_strlen(str[i]);
		if (len != cnt)
			return (-1);
		i++;
	}
	if (size != i - 1)
		return (-1);
	return (0);
}
