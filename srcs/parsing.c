/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:30:13 by grannou           #+#    #+#             */
/*   Updated: 2022/04/05 22:09:46 by grannou          ###   ########.fr       */
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
/* SO LONG PART
char	get_next_tile(t_data *data, int move)
{
	int		x;
	int		y;
	char	next_tile;

	x = data->game->player_x;
	y = data->game->player_y;
	if (move == UP)
		next_tile = data->array[y - 1][x];
	if (move == DOWN)
		next_tile = data->array[y + 1][x];
	if (move == LEFT)
		next_tile = data->array[y][x - 1];
	if (move == RIGHT)
		next_tile = data->array[y][x + 1];
	return (next_tile);
}

void	replace_map_char(t_data **data, char new)
{
	(*data)->array[(*data)->game->player_y][(*data)->game->player_x] = new;
}

void	handle_collectibles(t_data **data, char next_tile)
{
	if (next_tile == 'C' && (*data)->game->coll > 0)
	{
		(*data)->game->coll--;
		replace_map_char(data, '0');
	}
}
*/

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
	int	height;
	int	width;

	x = 0;
	y = 0;
	height = (*data)->map_height;
	width = (*data)->map_width;

	if (is_not_only_one_or_space_str((*data)->map[0]))
		clear_data_syntax_exit(data, 0, (*data)->map[0], NCLOSEDMAP);
	if (is_not_only_one_or_space_str((*data)->map[height - 1]))
		clear_data_syntax_exit(data, (height - 1), (*data)->map[height - 1], NCLOSEDMAP);
	// while (y < height - 1)
	// {
		// x = 0;
		// while (x < width - 1)
		// {
			// if ((*data)->map[y][x] == '0')
			// {
				// if (y - 1 < 0 || (y - 1 >= 0 && (*data)->map[y - 1][x] == ' '))
					// clear_data_exit(data, NCLOSEDMAP);
				// if (y + 1 > (*data)->map_height || (y + 1 <= (*data)->map_height && (*data)->map[y + 1][x] == ' '))
					// clear_data_exit(data, NCLOSEDMAP);
				// if (x - 1 < 0 || (x - 1 >= 0 && (*data)->map[y][x] - 1 == ' '))
					// clear_data_exit(data, NCLOSEDMAP);
				// if (x + 1 > (*data)->map_width || (x + 1 > (*data)->map_width && (*data)->map[y][x + 1] == ' '))
					// clear_data_exit(data, NCLOSEDMAP);
			// }
			// x++;
		// }
		// y++;
	// }
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
