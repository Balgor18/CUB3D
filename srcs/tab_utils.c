/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:10:53 by grannou           #+#    #+#             */
/*   Updated: 2022/03/25 19:11:33 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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