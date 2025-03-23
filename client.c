/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:52:09 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/23 12:10:51 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

#define SIGNAL_DELAY_US 100

void	handler_ack(int signum)
{
	(void)signum;
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	send_signal(pid_t server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			kill(server_pid, SIGUSR2);
			ft_printf("Char: %c | Bit: %d | Signal: SIGUSR2\n", c, bit);
		}
		else
		{
			kill(server_pid, SIGUSR1);
			ft_printf("Char: %c | Bit: %d | Signal: SIGUSR1\n", c, bit);
		}
		usleep(SIGNAL_DELAY_US);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	signal(SIGUSR1, handler_ack);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_printf("Sending: %s to PID %d\n", message, server_pid);
	i = 0;
	while (message[i])
	{
		send_signal(server_pid, message[i]);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
