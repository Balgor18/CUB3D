/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:30:13 by grannou           #+#    #+#             */
/*   Updated: 2022/04/04 18:53:36 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

// SI tu es un 0 dans la map et si (side est espace) OU (side n'existe pas)
// clear


void	check_closed_map(t_data **data)
{
	int	x;
	int	y;
	int	side[4];

	y = 0;
	bzero_int_tab(side, 4, 0);
	printf("side[MORTH] = %d\nside[SOUTH] = %d\nside[WEST] = %d\nside[EAST] = %d\n", \
		side[NORTH], side[SOUTH], side[WEST], side[EAST]);
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if ((*data)->map[y][x] == '0')
			{
				printf(YELLOW "map[y][x] = [%c]" RESET "\n", (*data)->map[y][x]);
				if (y - 1 > 0)
					side[NORTH] = (*data)->map[y - 1][x];
				if (y + 1 < (*data)->map_height)
					side[SOUTH] = (*data)->map[y + 1][x];
				if (x - 1 > 0)
					side[EAST] = (*data)->map[y][x - 1];
				if (x + 1 < (*data)->map_width)
					side[WEST] = (*data)->map[y][x + 1];
				printf("side[MORTH] = %d\nside[SOUTH] = %d\nside[WEST] = %d\nside[EAST] = %d\n", \
					side[NORTH], side[SOUTH], side[WEST], side[EAST]);
				if (side[NORTH] == 0 || side[SOUTH] == 0 || side[EAST] == 0 || side[WEST] == 0)
				{
					printf("x = %d, y = %d\n", x, y);
					clear_data_exit(data, NCLOSEDMAP);
				}
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
	check_closed_map(data);
	print_data(*data);
}
