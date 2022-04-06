/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:22:59 by grannou           #+#    #+#             */
/*   Updated: 2022/04/06 03:30:46 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	open_all_textures(t_data **data, int *fd)
{
	fd[NORTH] = open((*data)->north_texture, O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, O_RDONLY);
	fd[WEST] = open((*data)->west_texture, O_RDONLY);
	fd[EAST] = open((*data)->east_texture, O_RDONLY);
}

static void	close_error_exit(t_data **data, int *fd)
{
	if (fd[NORTH] == -1)
	{
		close(fd[NORTH]);
		clear_data_exit(data, OPENNOTEX);
	}
	fd[SOUTH] = open((*data)->south_texture, O_RDONLY);
	if (fd[SOUTH] == -1)
	{
		close(fd[SOUTH]);
		clear_data_exit(data, OPENSOTEX);
	}
	fd[WEST] = open((*data)->west_texture, O_RDONLY);
	if (fd[WEST] == -1)
	{
		close(fd[WEST]);
		clear_data_exit(data, OPENWETEX);
	}
	fd[EAST] = open((*data)->east_texture, O_RDONLY);
	if (fd[EAST] == -1)
	{
		close(fd[EAST]);
		clear_data_exit(data, OPENEATEX);
	}
}

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

// printf("In check texture size, width = %d, height = %d\n\n", width, height);
static int	check_texture_size(char *path, void *mlx)
{
	void	*image;
	int		width;
	int		height;
	int		fd;

	image = NULL;
	width = 0;
	height = 0;
	fd = 0;
	image = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!image || width != 64 || height != 64)
	{
		mlx_destroy_image(mlx, image);
		return (EXIT_FAILURE);
	}
	mlx_destroy_image(mlx, image);
	return (EXIT_SUCCESS);
}

// Use mlx to image to fill width and height et elles doivent etre de 64x64
// init mlx et return in ptr mlx
// call mlx_xp_file_to_image to fill width and height
void	check_open_textures(t_data **data)
{
	void	*mlx;
	int		fd[4];

	bzero_int_tab(fd, 4, 0);
	mlx = mlx_init();
	if (!mlx)
		clear_data_exit(data, MLXFAIL);
	open_all_textures(data, fd);
	if (fd[NORTH] == -1 || fd[SOUTH] == -1 || fd[WEST] == -1 || fd [EAST] == -1)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		close_error_exit(data, fd);
	}
	if (check_texture_size((*data)->north_texture, mlx))
		clear_mlx_fd_data_exit(data, mlx, fd, SIZENOTEX);
	if (check_texture_size((*data)->south_texture, mlx))
		clear_mlx_fd_data_exit(data, mlx, fd, SIZESOTEX);
	if (check_texture_size((*data)->west_texture, mlx))
		clear_mlx_fd_data_exit(data, mlx, fd, SIZEWETEX);
	if (check_texture_size((*data)->east_texture, mlx))
		clear_mlx_fd_data_exit(data, mlx, fd, SIZEEATEX);
	close_all_textures(fd);
	free(mlx);
}
