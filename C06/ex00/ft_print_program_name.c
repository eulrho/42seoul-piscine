/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:56:50 by erho              #+#    #+#             */
/*   Updated: 2023/09/06 15:00:59 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		i++;
		argv++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	if (argc != 1)
		return (0);
	write(1, argv[0], ft_strlen(argv[0]));
	write(1, "\n", 1);
	return (0);
}
