/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 10:09:46 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	exit (EXIT_FAILURE);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

t_map	*ft_lst_create(char *line)
{
	t_map	*elem;

	elem = (t_map *)malloc(sizeof(t_map));
	if (!elem)
		return (NULL);
	elem->mapline = line;
	elem->line_size = ft_strlen(line);
	elem->next = NULL;
	return (elem);
}

void	ft_lst_clear(t_map **map)
{
	t_map	*ptr;
	t_map	*next;

	ptr = *map;
	while (ptr)
	{
		next = ptr->next;
		free(ptr->mapline);
		free(ptr);
		ptr = next;
	}
}

t_map	*ft_lstlast(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

t_map	*ft_lst_addback(t_map **map, t_map *elem)
{
	if (*map)
		ft_lstlast(*map)->next = elem;
	else
		*map = elem;
	return (*map);
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

void	basic_parsing(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
		printf("Go to parsing\n");
	else if (argc == 1)
		exit_error(MARG);
	else if (argc > 2)
		exit_error(TMARG);
}

void	parsing(int argc, char **argv)
{
	basic_parsing(argc, argv);
}

int	main(int argc, char **argv)
{
	parsing(argc, argv);

	return (EXIT_SUCCESS);
}
