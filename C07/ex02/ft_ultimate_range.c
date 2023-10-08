/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:27:56 by erho              #+#    #+#             */
/*   Updated: 2023/09/09 18:32:26 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	len;
	long long	idx;
	int			*res;
	int			temp;

	len = max - min;
	temp = min;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	res = (int *)malloc(sizeof(int) * len);
	if (res == 0)
		return (-1);
	idx = 0;
	while (idx < len)
		res[idx++] = min++;
	*range = res;
	return (max - temp);
}
