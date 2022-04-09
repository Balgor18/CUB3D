/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:20:30 by grannou           #+#    #+#             */
/*   Updated: 2022/04/09 19:25:02 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_not_only_one_or_space_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	check_side(t_data **data, int x, int y, int direction)
{
	if (direction == NORTH && (*data)->map[y - 1][x] == ' ')
		clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
	if (direction == SOUTH && (*data)->map[y + 1][x] == ' ')
		clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
	if (direction == WEST && (*data)->map[y][x - 1] == ' ')
		clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
	if (direction == EAST && (*data)->map[y][x + 1] == ' ' )
		clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
}

static void	check_first_last_char(t_data **data)
{
	int		y;
	char	**map;
	int		width;

	y = 1;
	map = (*data)->map;
	width = (*data)->map_width;
	while (y < (*data)->map_height - 2)
	{
		if (map[y][0] == '0' || map[y][width - 1] == '0')
			clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
		y++;
	}
}

static void	check_inner_map(t_data **data)
{
	int	x;
	int	y;

	y = 1;
	while (y < (*data)->map_height)
	{
		x = 1;
		while (x < (*data)->map_width)
		{
			if ((*data)->map[y][x] == '0')
			{
				check_side(data, x, y, NORTH);
				check_side(data, x, y, SOUTH);
				check_side(data, x, y, WEST);
				check_side(data, x, y, EAST);
			}
			x++;
		}
		y++;
	}
}

void	check_closed_map(t_data **data)
{
	if (is_not_only_one_or_space_str((*data)->map[0]))
		clear_data_nclosedmap_exit(data, 0, NCLOSEDMAP);
	if (is_not_only_one_or_space_str((*data)->map[(*data)->map_height - 1]))
		clear_data_nclosedmap_exit(data, ((*data)->map_height - 1), NCLOSEDMAP);
	check_first_last_char(data);
	check_inner_map(data);
}
