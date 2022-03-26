/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:54:09 by grannou           #+#    #+#             */
/*   Updated: 2022/03/26 14:04:48 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_north_texture(t_data **data, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "NO ", 3) == 0)
		{
			(*data)->north_texture = sub_trim_str(tmp->line, "NO ");
			if (!(*data)->north_texture)
				clear_all_exit(data, list, NORTHFAIL);
		}
		tmp = tmp->next;
	}
}

static void	get_south_texture(t_data **data, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "SO ", 3) == 0)
		{
			(*data)->north_texture = sub_trim_str(tmp->line, "SO ");
			if (!(*data)->north_texture)
				clear_all_exit(data, list, SOUTHFAIL);
		}
		tmp = tmp->next;
	}
}

static void	get_west_texture(t_data **data, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "WE ", 3) == 0)
		{
			(*data)->north_texture = sub_trim_str(tmp->line, "WE ");
			if (!(*data)->north_texture)
				clear_all_exit(data, list, WESTFAIL);
		}
		tmp = tmp->next;
	}
}

static void	get_east_texture(t_data **data, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "EA ", 3) == 0)
		{
			(*data)->north_texture = sub_trim_str(tmp->line, "EA ");
			if (!(*data)->north_texture)
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
	*data = (t_data *)malloc(sizeof(t_data) * 1);
	if (!*data)
		clear_all_exit(data, list, DATAFAIL);
	get_north_texture(data, list);
	get_south_texture(data, list);
	get_west_texture(data, list);
	get_east_texture(data, list);
	// get_floor_rgb(data, list);
	// get_ceiling_rgb(data, list);
}