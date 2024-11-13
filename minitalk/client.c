#include "minitalk.h"

int	sleeper(int len)
{
	if (len <= 10000)
		return (50);
	else if (len <= 30000)
		return (100);
	else if (len <= 60000)
		return (300);
	else if (len <= 100000)
		return (500);
	else
		return (10000);
}

void	send_string(char *str, int id)
{
	int	i;
	int	len;
	int	bits;

	bits = 7;
	len = ft_strlen(str) + 1;
	i = 0;
	while (len--)
	{
		while (bits >= 0)
		{
			if (str[i] >> bits & 1)
			{
				kill(id, SIGUSR1);
				ft_printf("1");
			}
			else
			{
				kill(id, SIGUSR2);
				ft_printf("0");
			}
			bits--;
			usleep(sleeper(ft_strlen(str)));
		}
		i++;
		bits = 7;
		ft_printf("\n");
	}
	usleep(ft_strlen(str));
	return ;
}

int	main(int ac, char **av)
{
	if (3 != ac)
	{
		ft_printf("error: Type ./client server_pid \"string\"");
		return (1);
	}
	send_string(av[2], ft_atoi(av[1]));
	return (0);
}
