/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:10:04 by erho              #+#    #+#             */
/*   Updated: 2023/09/06 18:20:31 by erho             ###   ########.fr       */
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

void	ft_rev_params(int argc, char *argv[])
{
	int	i;

	i = argc;
	while (--i > 0)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	ft_rev_params(argc, argv);
	return (0);
}
