/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:30:13 by grannou           #+#    #+#             */
/*   Updated: 2022/04/05 22:29:32 by grannou          ###   ########.fr       */
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

int	is_not_only_one_or_space_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

// CHECK QUE FIRST LINE EST ONLY 1 OR SPACE
// CHECK QUE LAST LINE EST ONLY 1 OR SPACE
// CHECK QUE ALL LINES START WITH 1 OR SPACE
// CHECK QUE ALL LINES END WITH 1 OR SPACE
// START CHECK INNER MAP (MAP[1][1] ---> MAP[HEIGHT - 1][WIDTH -1]
// SI MAP[Y][X] EST UN 0
	// SI [Y-1][X] OU [Y+1][X] OU [Y][X-1] OU [Y][X+1] NEST PAS 0 OU 1
	// ALORS MAP EST NON FERMEE
void	check_closed_map(t_data **data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (is_not_only_one_or_space_str((*data)->map[0]))
		clear_data_syntax_exit(data, 0, (*data)->map[0], NCLOSEDMAP);
	if (is_not_only_one_or_space_str((*data)->map[(*data)->map_height - 1]))
		clear_data_syntax_exit(data, ((*data)->map_height - 1), \
			(*data)->map[(*data)->map_height - 1], NCLOSEDMAP);
	while (++y < (*data)->map_height - 2)
	{
		x = 1;
		while (x < (*data)->map_width - 2)
		{
			check_north_side((*data)->map[y][x]);
			check_south_side((*data)->map[y][x]);
			check_west_side((*data)->map[y][x]);
			check_east_side((*data)->map[y][x]);
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
