/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:46:10 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 02:58:37 by grannou          ###   ########.fr       */
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

// for directory texture
void	open_all_dir_textures(t_data **data, int *fd, void *mlx)
{
	fd[NORTH] = open((*data)->north_texture, __O_DIRECTORY | O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, __O_DIRECTORY | O_RDONLY);
	fd[WEST] = open((*data)->west_texture, __O_DIRECTORY | O_RDONLY);
	fd[EAST] = open((*data)->east_texture, __O_DIRECTORY | O_RDONLY);
	if (fd[NORTH] != -1 || fd[SOUTH] != -1 || fd[WEST] != -1 || fd [EAST] != -1)
	{
		mlx_destroy_display(mlx);
		close_dir_error_exit(data, fd);
	}
}

	// printf("In open all textures\n");
void	open_all_textures(t_data **data, int *fd, void *mlx)
{
	fd[NORTH] = open((*data)->north_texture, O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, O_RDONLY);
	fd[WEST] = open((*data)->west_texture, O_RDONLY);
	fd[EAST] = open((*data)->east_texture, O_RDONLY);
	if (fd[NORTH] == -1 || fd[SOUTH] == -1 || fd[WEST] == -1 || fd [EAST] == -1)
	{
		mlx_destroy_display(mlx);
		close_error_exit(data, fd);
	}
}

int	check_close(int fd, t_list *list)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		clear_list_exit(&list, CLOSEERR);
	return (EXIT_SUCCESS);
}

	// printf("In close all textures\n");
void	close_all_textures(int *fd)
{
	if (fd[NORTH] != -1)
		close(fd[NORTH]);
	else if (fd[SOUTH] != -1)
		close(fd[SOUTH]);
	else if (fd[WEST] != -1)
		close(fd[WEST]);
	else if (fd[EAST] != -1)
		close(fd[EAST]);
}
