/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:22:27 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/15 00:51:47 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(int pid, char *str)
{
    int i;
    int j;
    int bit;

    i = 0;
    while (str[i])
    {
        j = 0;
        while (j <= 7)
        {
            bit = (str[i] >> j) & 1;
            if (bit == 1)
                kill(pid, SIGUSR1);
            else
                kill(pif, SIGUSR2);
            j++;
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;

    if(argc != 3)
    {
        write(1, "Usage: ./client [PID] [Message]\n", 32);
        return (1);
    } 
    pid = ft_atoi(argv[1]);
    send_signal(pid, argv[2]);
    return (0);
    
}