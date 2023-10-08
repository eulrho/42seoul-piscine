/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:01:20 by erho              #+#    #+#             */
/*   Updated: 2023/08/28 10:08:28 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	idx;

	idx = 0;
	while (idx < size - 1)
	{
		if (tab[idx] > tab[idx + 1])
		{
			temp = tab[idx];
			tab[idx] = tab[idx + 1];
			tab[idx + 1] = temp;
		}
		idx++;
	}
	size--;
	if (size > 1)
		ft_sort_int_tab(tab, size);
}
