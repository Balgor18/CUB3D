/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:54:09 by grannou           #+#    #+#             */
/*   Updated: 2022/04/06 17:50:26 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map_size(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		height;
	int		width;

	tmp = *list;
	height = 0;
	width = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (tmp)
	{
		height++;
		if (width < ft_strlen(tmp->line))
			width = ft_strlen(tmp->line);
		tmp = tmp->next;
	}
	(*data)->map_height = height;
	(*data)->map_width = width;
}

void	init_map(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	(*data)->map = (char **)malloc(sizeof(char *) * ((*data)->map_height + 1));
	if (!(*data)->map)
		clear_all_exit(data, list, MAPFAIL);
	while (i < (*data)->map_height)
	{
		(*data)->map[i] = (char *)malloc(sizeof(char) * \
			((*data)->map_width + 1));
		if (!(*data)->map[i])
		{
			free_array((*data)->map);
			clear_all_exit(data, list, MAPFAIL);
		}
		(*data)->map[i] = ft_memset((*data)->map[i], ' ', (*data)->map_width);
		(*data)->map[i][(*data)->map_width] = '\0';
		i++;
	}
	(*data)->map[i] = NULL;
}

char	*copy_str(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	fill_map(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (i < (*data)->map_height && tmp)
	{
		(*data)->map[i] = copy_str((*data)->map[i], tmp->line);
		tmp = tmp->next;
		i++;
	}
}

void	fill_data(t_data **data, t_list **list)
{
	init_data(data, list);
	fill_texture(data, list, &(*data)->north_texture, "NO ");
	fill_texture(data, list, &(*data)->south_texture, "SO ");
	fill_texture(data, list, &(*data)->west_texture, "WE ");
	fill_texture(data, list, &(*data)->east_texture, "EA ");
	fill_rgb(data, list, &(*data)->floor_rgb, "F ");
	fill_rgb(data, list, &(*data)->ceiling_rgb, "C ");
	get_map_size(data, list);
	init_map(data, list);
	fill_map(data, list);
	get_player_infos(data);
}
