/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:13:13 by grannou           #+#    #+#             */
/*   Updated: 2022/04/06 02:50:54 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data **data, t_list **list)
{
	*data = (t_data *)malloc(sizeof(t_data) * 1);
	if (!*data)
		clear_all_exit(data, list, DATAFAIL);
	(*data)->map_height = 0;
	(*data)->map_width = 0;
	(*data)->map = NULL;
	(*data)->north_texture = NULL;
	(*data)->south_texture = NULL;
	(*data)->west_texture = NULL;
	(*data)->east_texture = NULL;
	(*data)->floor_rgb = 0;
	(*data)->ceiling_rgb = 0;
}
