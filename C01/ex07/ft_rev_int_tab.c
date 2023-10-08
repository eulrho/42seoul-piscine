/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:43:58 by erho              #+#    #+#             */
/*   Updated: 2023/08/27 15:18:10 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	idx;
	int	n;

	idx = 0;
	n = size / 2;
	while (n--)
	{
		temp = tab[idx];
		tab[idx] = tab[size - idx - 1];
		tab[size - idx - 1] = temp;
		idx++;
	}
}
