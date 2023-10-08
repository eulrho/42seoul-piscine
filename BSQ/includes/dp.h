/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:18:41 by erho              #+#    #+#             */
/*   Updated: 2023/09/13 19:08:16 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DP_H
# define DP_H

typedef struct _dp_map
{
	int	max_row;
	int	max_col;
	int	max_size;
}	t_dp_map;

typedef struct _map
{
	char	obstacle;
	char	empty;
	char	box;
	int		rows;
	int		cols;
}	t_map;

char	**create_map(char *buff);
int		find_square(char **map);
char	**ft_split(char *str);

#endif