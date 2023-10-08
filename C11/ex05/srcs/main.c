/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:43:05 by erho              #+#    #+#             */
/*   Updated: 2023/09/12 12:40:42 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calculation.h"
#include "ft_string.h"

int	ft_valid(char symbol)
{
	if (symbol == '+')
		return (0);
	else if (symbol == '-')
		return (1);
	else if (symbol == '*')
		return (2);
	else if (symbol == '/')
		return (3);
	else if (symbol == '%')
		return (4);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	symbol;

	if (argc != 4)
		return (0);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (ft_strlen(argv[2]) != 1)
		ft_putnbr(0);
	else
	{
		symbol = argv[2][0];
		if (ft_valid(symbol) != -1)
			ft_control_calculation(num1, ft_valid(symbol), num2);
		else
			ft_putnbr(0);
	}
	ft_putstr("\n");
	return (0);
}
