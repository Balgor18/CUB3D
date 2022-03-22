/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:19:52 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 10:38:39 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_extension(char *str, char *ext)
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

void	basic_parsing(int argc, char **argv)
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

static int	recursive_gnl(int fd, char **line, int index)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == -1)
		return (-1);
	if (ret == 1 && buf != '\n')
	{
		if (recursive_gnl(fd, line, index + 1) == -1)
			return (-1);
		(*line)[index] = buf;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
		if (!(*line))
			return (-1);
		(*line)[index] = '\0';
	}
	return (ret);
}

static int	get_next_line(int fd, char **line)
{
	int	ret;

	ret = recursive_gnl(fd, line, 0);
	if (!line || ret == -1)
		return (-1);
	return (ret);
}

void	fill_map(int fd, t_map **map)
{
	char	*line;
	t_map	*elem;
	int		ret;

	line = NULL;
	elem = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		elem = ft_lst_create(line);
		if (!elem)
			clear_map_free_line_exit(map, line);
		*map = ft_lst_addback(map, elem);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
	{
		if (line[0] != '\0')
			*map = ft_lst_addback(map, elem);
		free(line);
	}
	else
		clear_map_free_line_exit(map, line);
}

void	parsing(int argc, char **argv)
{
	int	fd;
	t_map	*map;

	fd = 0;
	map = NULL;
	basic_parsing(argc, argv);
	check_open(argv[1], &fd);
	fill_map(fd, &map);
	printf("After fill map Before print list\n");
	print_list(map);
	check_close(fd, map);
}