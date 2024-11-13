/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:49 by francima          #+#    #+#             */
/*   Updated: 2024/11/13 14:37:26 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//include
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"
# include <signal.h>


//structures

typedef struct s_bit_state
{
	int	current_char;
	int	bit;
	char	*string;
	
}	t_bits_state;
//functions
//
//server
char	*join_bit(char *str, char n);
void	sig_handler(int signum, siginfo_t *info, void *context);
//client
int		sleeper(int len);
void	send_string(char *str, int id);
#endif
