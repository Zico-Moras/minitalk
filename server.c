/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:42:22 by francima          #+#    #+#             */
/*   Updated: 2024/11/13 14:45:40 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*join_bit(char *str, char n)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char) + 1);
		str[i] = n;
		str[++i] = '\0';
		return (str);
	}
	new = (char *)malloc((ft_strlen(str) + 1) * sizeof(char) + 1);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = n;
	new[++i] = '\0';
	free(str);
	return (new);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static t_bits_state	state;
	(void)context;

	usleep(500);
	if (signum == SIGUSR1)
	{
		state.current_char |= (1 << (7 - state.bit));
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);

	state.bit++;
	if (state.bit == 8)
	{
		if (state.current_char == '\0')
		{
			ft_printf("%s\n", state.string);
			free(state.string);
			state.string = NULL;
		}
		else
			state.string = join_bit(state.string, state.current_char);
		state.bit = 0;
		state.current_char = 0;
	}
}

int	main(void)
{
	int	id;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	id = getpid();
	ft_printf("Server PID: %d\n", id);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
