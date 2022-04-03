/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:22:59 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 01:56:58 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

	// printf("In open all textures\n");
static void	open_all_textures(t_data **data, int *fd)
{
	fd[NORTH] = open((*data)->north_texture, O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, O_RDONLY);
	fd[WEST] = open((*data)->west_texture, O_RDONLY);
	fd[EAST] = open((*data)->east_texture, O_RDONLY);
}

// for directory texture
static void	open_all_dir_textures(t_data **data, int *fd)
{
	fd[NORTH] = open((*data)->north_texture, __O_DIRECTORY | O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, __O_DIRECTORY | O_RDONLY);
	fd[WEST] = open((*data)->west_texture, __O_DIRECTORY | O_RDONLY);
	fd[EAST] = open((*data)->east_texture, __O_DIRECTORY | O_RDONLY);
}

	// printf("In close error exit\n");
static void	close_error_exit(t_data **data, int *fd)
{
	if (fd[NORTH] == -1)
	{
		// close(fd[NORTH]);
		close_all_textures(fd);
		clear_data_exit(data, OPENNOTEX);
	}
	if (fd[SOUTH] == -1)
	{
		// close(fd[SOUTH]);
		close_all_textures(fd);
		clear_data_exit(data, OPENSOTEX);
	}
	if (fd[WEST] == -1)
	{
		// close(fd[WEST]);
		close_all_textures(fd);
		clear_data_exit(data, OPENWETEX);
	}
	if (fd[EAST] == -1)
	{
		// close(fd[EAST]);
		close_all_textures(fd);
		clear_data_exit(data, OPENEATEX);
	}
}

// for directory texture
static void	close_dir_error_exit(t_data **data, int *fd)
{
	if (fd[NORTH] != -1)
	{
		// close(fd[NORTH]);
		close_all_textures(fd);
		clear_data_exit(data, OPENDIRNOTEX);
	}
	if (fd[SOUTH] != -1)
	{
		// close(fd[SOUTH]);
		close_all_textures(fd);
		clear_data_exit(data, OPENDIRSOTEX);
	}
	if (fd[WEST] != -1)
	{
		// close(fd[WEST]);
		close_all_textures(fd);
		clear_data_exit(data, OPENDIRWETEX);
	}
	if (fd[EAST] != -1)
	{
		// close(fd[EAST]);
		close_all_textures(fd);
		clear_data_exit(data, OPENDIREATEX);
	}
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

	// printf("In check texture size\n");
// printf("In check texture size, width = %d, height = %d\n\n", width, height);
	// printf("test: %p\n%s\n%d\n%d\n", mlx, path, width, height);
	// printf("test: %p\n%s\n%d\n%d\n", mlx, path, width, height);
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

	// printf("In check open textures\n");
void	check_open_textures(t_data **data)
{
	void	*mlx;
	int		fd[4];

	bzero_int_tab(fd, 4, 0);
	mlx = mlx_init();
	if (!mlx)
		clear_data_exit(data, MLXFAIL);

	open_all_dir_textures(data, fd);
	if (fd[NORTH] != -1 || fd[SOUTH] != -1 || fd[WEST] != -1 || fd [EAST] != -1)
	{
		mlx_destroy_display(mlx);
		close_dir_error_exit(data, fd);
	}

	bzero_int_tab(fd, 4, 0);
	open_all_textures(data, fd);
	if (fd[NORTH] == -1 || fd[SOUTH] == -1 || fd[WEST] == -1 || fd [EAST] == -1)
	{
		mlx_destroy_display(mlx);
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
	mlx_destroy_display(mlx);
}
