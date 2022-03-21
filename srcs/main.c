/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 11:17:08 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	exit (EXIT_FAILURE);
}

int	ft_lst_size(t_map *map)
{
	int	i;

	i = 0;
	while (map)
	{
		i++;
		map = map->next;
	}
	return (i);
}

int	check_map_extension(char *str, char *ext)
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

void	basic_parsing(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_map_extension(argv[1], ".cub"))
			exit_error(WEXT);
	}
	else if (argc == 1)
		exit_error(MARG);
	else if (argc > 2)
		exit_error(TMARG);
}

void	parsing(int argc, char **argv)
{
	int	fd;
	t_map	*map;

	fd = 0;
	map = NULL;
	basic_parsing(argc, argv);
	check_open(argv[1], &fd);
	// fill_map(fd, &map);
	check_close(fd, map);
}


int	main(int argc, char **argv)
{
	parsing(argc, argv);

	return (EXIT_SUCCESS);
}

/* SO LONG PARSING
static int	check_open(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY | O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		exit_error (OPENDIRERR);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error(OPENERR);
	return (fd);
}

static int	check_close(int fd, t_map *map)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		clear_map_exit(&map, CLOSEERR);
	return (EXIT_SUCCESS);
}

static void	check_argc_and_map_extension(int argc, char **argv)
{
	if (argc == 2)
		if (check_map_extension(argv[1], ".ber"))
			exit_error(WEXT);
	if (argc == 1)
		exit_error(MARG);
	if (argc > 2)
		exit_error(TMARG);
}

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