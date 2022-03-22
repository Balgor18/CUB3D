/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:58:46 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 08:59:44 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_map_exit(t_map **map, char *msg)
{
	ft_lst_clear(map);
	exit_error(msg);
}

void	clear_map_free_line_exit(t_map **map, char *line)
{
	ft_lst_clear(map);
	free(line);
	exit_error(GNLFAIL);
}