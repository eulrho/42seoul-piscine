/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:22:38 by erho              #+#    #+#             */
/*   Updated: 2023/09/12 12:43:00 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calculation.h"
#include "ft_string.h"

void	ft_add(int num1, int num2)
{
	ft_putnbr(num1 + num2);
}

void	ft_sub(int num1, int num2)
{
	ft_putnbr(num1 - num2);
}

void	ft_mul(int num1, int num2)
{
	ft_putnbr(num1 * num2);
}

void	ft_div(int num1, int num2)
{
	if (num2 == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(num1 / num2);
}

void	ft_mod(int num1, int num2)
{
	if (num2 == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(num1 % num2);
}
