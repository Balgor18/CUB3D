/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:13:13 by grannou           #+#    #+#             */
/*   Updated: 2022/04/06 17:22:33 by fcatinau         ###   ########.fr       */
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
	(*data)->player_x = 0;
	(*data)->player_y = 0;
	(*data)->player_dir = '\0';
	(*data)->player_dir_radian = 0.0;
}

void	*ft_memset(void *b, int c, int len)
{
	while (len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

void	check_player_count(t_data **data)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (is_cardinal_char((*data)->map[y][x]))
				player++;
			x++;
		}
		y++;
	}
	if (player == 0)
		clear_data_exit(data, ZEROPMAP);
	if (player > 1)
		clear_data_exit(data, MULTIPMAP);
}

static void	get_dir_radian(t_data **data, char player_position)
{
	if (player_position == 'N')
		(*data)->player_dir_radian = M_PI / 2;
	else if (player_position == 'S')
		(*data)->player_dir_radian = 3 * (M_PI / 2);
	else if (player_position == 'W')
		(*data)->player_dir_radian = M_PI;
	else if (player_position == 'E')
		(*data)->player_dir_radian = 0.0;
}

void	get_player_infos(t_data **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (is_cardinal_char((*data)->map[y][x]))
			{
				(*data)->player_x = x;
				(*data)->player_y = y;
				(*data)->player_dir = (*data)->map[y][x];
				get_dir_radian(data, (*data)->map[y][x]);
			}
			x++;
		}
		y++;
	}
}
