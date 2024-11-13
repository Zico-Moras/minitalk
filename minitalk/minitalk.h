#ifndef MINITALK_H
# define MINITALK_H

//include
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"
# include <signal.h>

//functions
//
//server
char	*join_bit(char *str, char n);
void	sig_handler(int sig);
//client
int	sleeper(int len);
void	send_string(char *str, int id);
#endif
