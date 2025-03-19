/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:10:04 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/19 12:36:47 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	// return (n);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static int	character;

	i = 0;
	character = 0;
	(void)context;
	if (signum == SIGUSR1)
	{
		character |= (1 << i);
		i++;
	}
	else if (signum == SIGUSR2)
	{
		character |= (0 << i);
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", character);
		if (character == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	handler_ack(int signum)
{
	(void)signum;
	ft_printf("Signal received");
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: Sigaction SIGUSR1 is failed\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Sigaction SIGUSR2 is failed\n");
		return (1);
	}
	ft_putnbr(getpid());
	ft_printf("\n");
	while (1)
		pause();
	return (0);
}