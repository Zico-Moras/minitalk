/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:23:25 by francima          #+#    #+#             */
/*   Updated: 2024/11/13 13:24:53 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//includes
# include "../libft.h"

//functions

int	ft_printf(const char *str, ...);

int	print_hex(unsigned int nbr, int uplow);
int	print_unbr(unsigned int nbr);
int	print_nbr(int nbr);
int	print_str(char *str);
int	print_pointer(unsigned long *p);
int	print_adress(unsigned long p);

#endif
