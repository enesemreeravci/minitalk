/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:52:09 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/19 12:29:13 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

/* to convert the pid number because we are not allowed to use atoi() */
int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && ((*str == 32) || (*str >= 9 && *str <= 13)))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res - sign);
}

void	send_signal(int pid, char *str)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j <= 7)
		{
			bit = (str[i] >> j) & i;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Usage: ./client [PID] [Message]\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_signal(pid, argv[2]);
	return (0);
}
