/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:22:59 by grannou           #+#    #+#             */
/*   Updated: 2022/04/08 18:42:37 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_textures_extensions(t_data **data)
{
	if (check_extension((*data)->north_texture, ".xpm"))
		clear_data_exit(data, WNOEXT);
	else if (check_extension((*data)->south_texture, ".xpm"))
		clear_data_exit(data, WSOEXT);
	else if (check_extension((*data)->west_texture, ".xpm"))
		clear_data_exit(data, WWEEXT);
	else if (check_extension((*data)->east_texture, ".xpm"))
		clear_data_exit(data, WEAEXT);
}

void	close_error_exit(t_data **data, int *fd)
{
	close_all_textures(fd);
	if (fd[NORTH] == -1)
		clear_data_exit(data, OPENNOTEX);
	if (fd[SOUTH] == -1)
		clear_data_exit(data, OPENSOTEX);
	if (fd[WEST] == -1)
		clear_data_exit(data, OPENWETEX);
	if (fd[EAST] == -1)
		clear_data_exit(data, OPENEATEX);
}

void	close_dir_error_exit(t_data **data, int *fd)
{
	if (fd[NORTH] != -1)
	{
		close_all_textures(fd);
		clear_data_exit(data, OPENDIRNOTEX);
	}
	if (fd[SOUTH] != -1)
	{
		close_all_textures(fd);
		clear_data_exit(data, OPENDIRSOTEX);
	}
	if (fd[WEST] != -1)
	{
		close_all_textures(fd);
		clear_data_exit(data, OPENDIRWETEX);
	}
	if (fd[EAST] != -1)
	{
		close_all_textures(fd);
		clear_data_exit(data, OPENDIREATEX);
	}
}

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

void	check_open_textures(t_data **data)
{
	void	*mlx;
	int		fd[4];

	bzero_int_tab(fd, 4, 0);
	mlx = mlx_init();
	if (!mlx)
		clear_data_exit(data, MLXINITFAIL);
	open_all_dir_textures(data, fd, mlx);
	bzero_int_tab(fd, 4, 0);
	open_all_textures(data, fd, mlx);
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
