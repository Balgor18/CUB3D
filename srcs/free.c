/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:58:46 by grannou           #+#    #+#             */
/*   Updated: 2022/03/23 02:18:21 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_list_exit(t_list **list, char *msg)
{
	ft_lst_clear(list);
	exit_error(msg);
}

void	clear_list_syntax_exit(t_list **list, int i, char *line, char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	printf("[%d] " YELLOW "[%s]" RESET"\n", i, line);
	ft_lst_clear(list);
	exit(EXIT_FAILURE);
}

void	clear_list_free_line_exit(t_list **list, char *line)
{
	ft_lst_clear(list);
	free(line);
	exit_error(GNLFAIL);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clear_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_map(data->map);
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	free(data);
}
