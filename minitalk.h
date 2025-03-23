/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:10:13 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/23 12:10:14 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	send_signal(pid_t server_pid, char c);
void	ft_putnbr(int n);
void	handler(int signum, siginfo_t *info, void *context);
void	handler_ack(int signum);
int		ft_atoi(char *str);

#endif