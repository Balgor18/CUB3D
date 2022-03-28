/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:30:13 by grannou           #+#    #+#             */
/*   Updated: 2022/03/28 15:42:29 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_extension(char *str, char *ext)
{
	int	len;
	int	len_ext;

	len = ft_strlen(str);
	len_ext = ft_strlen(ext);
	while ((str[len] == ext[len_ext]) && len > 0)
	{
		if (len_ext == 0)
			return (EXIT_SUCCESS);
		len--;
		len_ext--;
	}
	return (EXIT_FAILURE);
}

static void	check_argc(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_extension(argv[1], ".cub"))
			exit_error(WEXT);
	}
	else if (argc == 1)
		exit_error(MARG);
	else if (argc > 2)
		exit_error(TMARG);
}

static void	check_textures_extensions(t_data **data)
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

// Use mlx to image to fill width and height et elles doivent etre de 64x64
// init mlx et return in ptr mlx
// call mlx_xp_file_to_image to fill width and height
static void	check_open_textures(t_data **data)
{
	void	*mlx;
	void	*image;
	int		width;
	int		height;
	int		fd[4];

	mlx = NULL;
	image = NULL;
	width = 0;
	height = 0;
	bzero_int_tab(fd, 4, 0);
	fd[NORTH] = open((*data)->north_texture, O_RDONLY);
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
	close(fd[NORTH]);
	close(fd[SOUTH]);
	close(fd[WEST]);
	close(fd[EAST]);
}

/**
	@brief parse the map file. check the extension, open, syntax, dupplicates,
	values and fill data if correct to send to mlx

	@param argc main's argument count
	@param argv main's array of argument's strings
	@param data structure with all infos parsed in map file
	@return nothing
**/
void	parsing(int argc, char **argv, t_data **data)
{
	int		fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	check_argc(argc, argv);
	check_open(argv[1], &fd);
	fill_list(fd, &list);
	print_list(list);
	check_list_syntax(&list);
	check_list_duplicates(&list);
	check_close(fd, list);
	fill_data(data, &list);
	ft_lst_clear(&list);
	check_textures_extensions(data);
	check_open_textures(data);
	print_data(*data);
}
