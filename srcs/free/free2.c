/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:50:55 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 02:40:00 by grannou          ###   ########.fr       */
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
	free(*data);
}

void	clear_data_exit(t_data **data, char *msg)
{
	clear_data(data);
	exit_error(msg);
}

void	clear_all_exit(t_data **data, t_list **list, char *msg)
{
	if (*list)
		ft_lst_clear(list);
	if (data)
		clear_data(data);
	exit_error(msg);
}

void	clear_mlx_fd_data_exit(t_data **data, void *mlx, int *fd, char *msg)
{
	mlx_destroy_display(mlx);
	close_all_textures(fd);
	clear_data_exit(data, msg);
}
