/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:10:53 by grannou           #+#    #+#             */
/*   Updated: 2022/03/30 10:55:01 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	nbrlen(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (is_digit(*str))
	{
		i++;
		str++;
	}
	while (*str == ' ')
		str++;
	if (is_digit(*str))
		return (-1);
	return (i);
}

/**
	@brief fill an int tab with given value, usually 0

	@param tab pointer to the tab
	@param tab_size size of the tab
	@param value value to fill the tab with
	@return nothing
**/
void	bzero_int_tab(int *tab, int tab_size, int value)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		tab[i] = value;
		i++;
	}
}

/**
 * @brief Create a trgb single int from 4 int. One byte containing 2^8 = 256
 * values, and RGB range is [0-255], we fit each color in a byte, because an
 * int is 4 bytes
 *
 * @param t transparency
 * @param r red
 * @param g green
 * @param b blie
 * @return int
**/
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
