/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:56:35 by eeravci           #+#    #+#             */
/*   Updated: 2025/01/15 16:39:03 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_recursive(int n, int *len)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		(*len)++;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_recursive(n / 10, len);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*len)++;
}

int	ft_printnumber(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	ft_putnbr_recursive(n, &len);
	return (len);
}
