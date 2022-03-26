/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:50:55 by grannou           #+#    #+#             */
/*   Updated: 2022/03/26 20:06:11 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	clear_data(t_data **data)
{
	if (!*data)
		return ;
	if ((*data)->map)
		free_array((*data)->map);
	free((*data)->north_texture);
	free((*data)->south_texture);
	free((*data)->west_texture);
	free((*data)->east_texture);
	free((*data));
}

void	clear_all_exit(t_data **data, t_list **list, char *msg)
{
	clear_data(data);
	ft_lst_clear(list);
	exit_error(msg);
}
