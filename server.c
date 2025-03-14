/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:40:17 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/15 00:51:50 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " minitalk.h"

void handler(int signum, siginfo_t *info, void *context)
{
    static char c = 0;
    static int i = 0;

    (void)context;
    if (signum == SIGUSR1)
        c |= (1 << i);
    i++;
    if (i == 8)
    {
        write(1, &c, 1);
        if (c == '\0')
        {
            write(1, "\n", 1);
            kill(info->si_pid, SIGUSR1);
        }
        c = 0;
        i = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

void handler_ack(int signum)
{
    (void)signum;
    write(1, "Signal received\n", 16);
}

int main(void)
{
    struct sigaction sa;
    struct sigaction sa_ack;

    sa.sa_handler = handler;
    sa_ack.sa_handler = handler_ack;
    sigemptyset(&sa.sa_mask);
    sigemptyset(&sa_ack.sa_mask);
    sa.sa_flags = 0;
    sa_ack.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGUSR1, &sa_ack, NULL);
    sigaction(SIGUSR2, &sa_ack, NULL);
    write(1, "PID: ", 5);
    ft_putnbr(getpid(), 1);
    write(1, "\n", 1);
    while (1)
        pause();
    return (0);
}