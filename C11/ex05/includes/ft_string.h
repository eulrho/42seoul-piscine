/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:43:30 by erho              #+#    #+#             */
/*   Updated: 2023/09/12 12:40:41 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

int		ft_check_valid(char *str, int *check_negative);
int		ft_number(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

#endif
