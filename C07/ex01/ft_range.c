/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:54 by erho              #+#    #+#             */
/*   Updated: 2023/09/09 18:26:46 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	len;
	int			*range;
	long long	idx;

	len = max - min;
	if (max <= min)
		return (0);
	range = (int *)malloc(sizeof(int) * len);
	idx = 0;
	while (idx < len)
		range[idx++] = min++;
	return (range);
}
