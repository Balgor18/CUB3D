/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:22:59 by grannou           #+#    #+#             */
/*   Updated: 2022/03/30 12:24:34 by grannou          ###   ########.fr       */
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

static void	close_all_textures(int *fd)
{
	close(fd[NORTH]);
	close(fd[SOUTH]);
	close(fd[WEST]);
	close(fd[EAST]);
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
	printf("In check texture size, width = %d, height = %d\n\n", width, height);
	if (!image || width != 64 || height != 64)
		return (EXIT_FAILURE);
	free(image);
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
		close_error_exit(data, fd);
	if (check_texture_size((*data)->north_texture, mlx))
		clear_data_exit(data, SIZENOTEX);
	if (check_texture_size((*data)->south_texture, mlx))
		clear_data_exit(data, SIZESOTEX);
	if (check_texture_size((*data)->west_texture, mlx))
		clear_data_exit(data, SIZEWETEX);
	if (check_texture_size((*data)->east_texture, mlx))
		clear_data_exit(data, SIZEEATEX);
	close_all_textures(fd);
	free(mlx);
}