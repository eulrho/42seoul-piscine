/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:31:26 by erho              #+#    #+#             */
/*   Updated: 2023/08/27 19:12:39 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_atoi(char *str)
{
	long long	num;
	int			i;

	i = 0;
	num = 0;
	if (str[0] == '-')
		return (-1);
	while (*(str + i) != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		else
			return (-2);
	}
	return (num);
}

int	check_exception(int args, char *argv[])
{
	int	check;

	check = 0;
	if (args != 3)
	{
		write(1, "Input value must be two\n", 24);
		check = 1;
	}
	if (argv[1][0] == '-' || argv[2][0] == '-')
	{
		write(1, "Input value must be pasitive\n", 30);
		check = 1;
	}
	if (ft_atoi(argv[1]) > 2147483647 || ft_atoi(argv[2]) > 2147483647)
	{
		write(1, "Input value must be within int type range\n", 41);
		check = 1;
	}
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[2]) == 0)
	{
		write(1, "Input value is 0\n", 17);
		check = 1;
	}
	return (check);
}

void	rush(int x, int y);

int	main(int poo, char *argv[])
{		
	if (check_exception(args, argv) == 1)
		return (0);
	rush (ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
