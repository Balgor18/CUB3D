/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:54:09 by grannou           #+#    #+#             */
/*   Updated: 2022/03/26 15:19:59 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_texture(t_data **data, t_list **list, char **dest, char *src)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, src, 3) == 0)
		{
			*dest = sub_trim_str(tmp->line, src);
			if (!*dest && (ft_strcmp(src, "NO ") == 0))
				clear_all_exit(data, list, NORTHFAIL);
			else if (!*dest && (ft_strcmp(src, "SO ") == 0))
				clear_all_exit(data, list, SOUTHFAIL);
			else if (!*dest && (ft_strcmp(src, "WE ") == 0))
				clear_all_exit(data, list, WESTFAIL);
			else if (!*dest && (ft_strcmp(src, "EA ") == 0))
				clear_all_exit(data, list, EASTFAIL);
		}
		tmp = tmp->next;
	}
}

/*
void	get_rgb(t_data **data, t_list **list, int side)
*/

void	fill_data(t_data **data, t_list **list)
{
	init_data(data, list);
	fill_texture(data, list, &(*data)->north_texture, "NO ");
	fill_texture(data, list, &(*data)->south_texture, "SO ");
	fill_texture(data, list, &(*data)->west_texture, "WE ");
	fill_texture(data, list, &(*data)->east_texture, "EA ");
	// get_floor_rgb(data, list);
	// get_ceiling_rgb(data, list);
}
