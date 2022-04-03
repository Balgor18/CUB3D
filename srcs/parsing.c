/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:30:13 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 18:14:23 by grannou          ###   ########.fr       */
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

	// printf("In check textures extensiions\n");
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

void	check_player(t_data **data)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (is_cardinal_char((*data)->map[y][x]))
				player++;
			x++;
		}
		y++;
	}
	if (player == 0)
		clear_data_exit(data, ZEROPMAP);
	if (player > 1)
		clear_data_exit(data, MULTIPMAP);
}

void	get_player_infos(t_data **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (is_cardinal_char((*data)->map[y][x]))
			{
				(*data)->player_x = x;
				(*data)->player_y = y;
				(*data)->player_dir = (*data)->map[y][x];
			}
			x++;
		}
		y++;
	}
}

/**
	@brief parse the map file. check the extension, open, syntax, dupplicates,
	values and fill data if correct to send to mlx

	@param argc main's argument count
	@param argv main's array of argument's strings
	@param data structure with all infos parsed in map file
	@return nothing
**/
	// printf("In parsing\n");
void	parsing(int argc, char **argv, t_data **data)
{
	int		fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	check_argc(argc, argv);
	check_open(argv[1], &fd);
	fill_list(fd, &list);
	check_list_syntax(&list);
	check_list_duplicates(&list);
	check_splitted_map(&list);
	check_close(fd, list);
	fill_data(data, &list);
	print_list(list);
	ft_lst_clear(&list);
	check_textures_extensions(data);
	check_open_textures(data);
	check_player(data);
	get_player_infos(data);
	print_data(*data);
}
