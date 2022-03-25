/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:10:53 by grannou           #+#    #+#             */
/*   Updated: 2022/03/25 19:20:18 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

// METTTRE ICI la fonction qui transforme les 3 int du split en un int hexa