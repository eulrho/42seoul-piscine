/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:45:30 by erho              #+#    #+#             */
/*   Updated: 2023/09/12 12:41:02 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CALCULATION_H
# define FT_CALCULATION_H

int		ft_nbrlen(int nb);
void	ft_putnbr(int nb);
void	insert_buff(int i, char *buff, int len_nb, int nb);
void	ft_control_calculation(int num1, int symbol, int num2);
void	ft_add(int num1, int num2);
void	ft_sub(int num1, int num2);
void	ft_mul(int num1, int num2);
void	ft_div(int num1, int num2);
void	ft_mod(int num1, int num2);

#endif
