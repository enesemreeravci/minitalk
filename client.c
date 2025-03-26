/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:52:09 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/26 13:07:04 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

#define SIGNAL_DELAY_US 100

/*
a placeholder signal handler.
registers to catch SIGUSR1 from the server as an "acknowledgment"
even though it's empty, it allows the client to continue safely without being interrupted
*/
void	handler_ack(int signum)
{
	(void)signum;
}

/*converts a string to an integer.
the client receives the server's pid as a string argument argv[1]
and needs to convert it to an integer to use with kill()*/
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

/*
sends one character to the server bit by bit by using UNIX signals.
if the bit Is 1, it sends SIGUSR2
if the bit is 0, it sends SIGUSR1
*/
void	send_signal(pid_t server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
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
