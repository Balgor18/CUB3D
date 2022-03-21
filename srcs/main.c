/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 11:30:39 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	exit (EXIT_FAILURE);
}

void	check_open(char *filename, int *fd)
{
	*fd = open(filename, O_DIRECTORY | O_RDONLY);
	if (*fd != -1)
	{
		close(*fd);
		exit_error (OPENDIRERR);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		exit_error(OPENERR);
}

void	clear_map_exit(t_map **map, char *msg)
{
	ft_lst_clear(map);
	exit_error(msg);
}

int	check_close(int fd, t_map *map)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		clear_map_exit(&map, CLOSEERR);
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	t_infos	*infos;

	infos = NULL;
	parsing(argc, argv);

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