/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:44:04 by eeravci           #+#    #+#             */
/*   Updated: 2025/01/15 16:06:09 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_recursive(unsigned int n, int is_uppercase, int *len)
{
	char	c;

	if (n >= 16)
		ft_puthex_recursive(n / 16, is_uppercase, len);
	c = "0123456789abcdef"[n % 16];
	if (is_uppercase && c >= 'a' && c <= 'f')
		c -= 32;
	write(1, &c, 1);
	(*len)++;
}

int	ft_printhex(unsigned int n, char format)
{
	int	len;
	int	is_uppercase;

	len = 0;
	is_uppercase = (format == 'X');
	ft_puthex_recursive(n, is_uppercase, &len);
	return (len);
}
