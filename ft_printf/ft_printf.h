/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:58:37 by eeravci           #+#    #+#             */
/*   Updated: 2025/01/15 15:40:08 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list args, const char format);
int	ft_printchar(int c);
int	ft_printstring(char *str);
int	ft_printnumber(int n);
int	ft_printunsigned(unsigned int n);
int	ft_printhex(unsigned int n, char format);
int	ft_printptr(unsigned long long ptr);
int	ft_printpercent(void);

#endif
