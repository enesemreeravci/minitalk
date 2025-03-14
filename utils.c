/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:17:52 by eeravci           #+#    #+#             */
/*   Updated: 2025/03/15 00:43:08 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_atoi(char *str)
{
    int sign;
    int result;

    sign = 1;
    result = 0;

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return (result * sign);
}

int ft_strlen(char *str)
{
    char *start;

    start = str;
    while(*str != '\0') 
        str++;
    return (str - start);
}

int ft_putnbr(int n)
{
    char c;
    if(n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if(n > 9)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
    return (n);
}