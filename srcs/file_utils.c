/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:46:10 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 01:58:45 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_open(char *filename, int *fd)
{
	*fd = open(filename, __O_DIRECTORY | O_RDONLY);
	if (*fd != -1)
	{
		close(*fd);
		exit_error(OPENDIRERR);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		exit_error(OPENERR);
}

int	check_close(int fd, t_list *list)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		clear_list_exit(&list, CLOSEERR);
	return (EXIT_SUCCESS);
}
/*
void	check_open_directory_texture(t_data **data, int cardinal)
{
	int	fd;

	fd = 0;
	printf("In check open dir texture\n");
	if (cardinal == NORTH)
		fd = open((*data)->north_texture, __O_DIRECTORY | O_RDONLY);
	else if (cardinal == SOUTH)
		fd = open((*data)->south_texture, __O_DIRECTORY | O_RDONLY);
	else if (cardinal == EAST)
		fd = open((*data)->east_texture, __O_DIRECTORY | O_RDONLY);
	else if (cardinal == WEST)
		fd = open((*data)->west_texture, __O_DIRECTORY | O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		if (cardinal == NORTH)
			clear_data_exit(data, OPENDIRNOTEX);
		else if (cardinal == SOUTH)
			clear_data_exit(data, OPENDIRSOTEX);
		else if (cardinal == WEST)
			clear_data_exit(data, OPENDIRWETEX);
		else if (cardinal == EAST)
			clear_data_exit(data, OPENDIREATEX);
	}
}

void	check_open_texture(t_data **data, int cardinal)
{
	int	fd;

	fd = 0;
	if (cardinal == NORTH)
		fd = open((*data)->north_texture, O_RDONLY);
	else if (cardinal == SOUTH)
		fd = open((*data)->south_texture, O_RDONLY);
	else if (cardinal == EAST)
		fd = open((*data)->east_texture, O_RDONLY);
	else if (cardinal == WEST)
		fd = open((*data)->west_texture, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		if (cardinal == NORTH)
			clear_data_exit(data, OPENNOTEX);
		else if (cardinal == SOUTH)
			clear_data_exit(data, OPENSOTEX);
		else if (cardinal == WEST)
			clear_data_exit(data, OPENWETEX);
		else if (cardinal == EAST)
			clear_data_exit(data, OPENEATEX);
	}
}
*/
