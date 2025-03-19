#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	send_signal(int pid, char *str);
void	ft_putnbr(int n);
void	handler(int signum, siginfo_t *info, void *context);
void	handler_ack(int signum);
int		ft_atoi(char *str);

#endif