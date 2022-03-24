/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/24 20:46:10 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	parsing(argc, argv, &data);
	return (EXIT_SUCCESS);
}

/* SO LONG PARSING
static void	check_valid_map(t_map **map)
{
	check_map_size(map);
	check_rectangle_map(map);
	check_map_chars(map);
	check_closed_map(map);
	check_items(map);
}
void	parse(t_data **data, int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = NULL;
	fd = 0;
	check_argc_and_map_extension(argc, argv);
	fd = check_open(argv[1]);
	fill_map(fd, &map);
	check_close(fd, map);
	check_valid_map(&map);
	*data = create_data(map);
	print_all(*data);
	if (!*data)
		return ;
	(*data)->array[(*data)->game->player_y][(*data)->game->player_x] = '0';
}

*/