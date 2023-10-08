/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_calculation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:38:06 by erho              #+#    #+#             */
/*   Updated: 2023/09/12 12:41:25 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calculation.h"

void	ft_putstr(char	*str);

void	ft_control_calculation(int num1, int symbol, int num2)
{
	void	(*f[5])(int, int);

	f[0] = ft_add;
	f[1] = ft_sub;
	f[2] = ft_mul;
	f[3] = ft_div;
	f[4] = ft_mod;
	f[symbol](num1, num2);
}
