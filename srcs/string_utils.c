/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:16:50 by grannou           #+#    #+#             */
/*   Updated: 2022/03/24 20:50:24 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_cardinal_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	is_color_char(char c)
{
	return (c == 'F' || c == 'C');
}
