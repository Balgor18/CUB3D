/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:50:10 by grannou           #+#    #+#             */
/*   Updated: 2022/03/24 01:52:24 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char    to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A'));
    return (c);
}

static int     get_digit(char c, int digits_in_base)
{
    int max_digit;
    if (digits_in_base <= 10)
        max_digit = digits_in_base + '0';
    else
        max_digit = digits_in_base - 10 + 'a';

    if (c >= '0' && c <= '9' && c <= max_digit)
        return (c - '0');
    else if (c >= 'a' && c <= 'f' && c <= max_digit)
        return (10 + c - 'a');
    else
        return (-1);
}

int     ft_atoi_base(char *str, int str_base)
{
    int result = 0;
    int sign = 1;
    int digit;

    if (*str == '-')
    {
        sign = -1;
        ++str;
    }

    while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
    {
        result = result * str_base;
        result = result + (digit * sign);
        ++str;
    }
    return (result);
}