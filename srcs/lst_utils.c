/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:29:16 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 09:15:50 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	elem->line_size = ft_strlen(elem->mapline);
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

void	print_list(t_map *map)
{
	int i;

	i = 0;
	printf("In print list\n");
	printf(GREEN "List:" RESET "\n");
	while (map)
	{
		printf("[%d] [len = %d] [%s]\n", i, map->line_size, map->mapline);
		i++;
		map = map->next;
	}
}