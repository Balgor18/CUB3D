/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:23 by grannou           #+#    #+#             */
/*   Updated: 2022/03/26 14:11:32 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	exit(EXIT_FAILURE);
}

void	print_list(t_list *list)
{
	int	i;

	i = 0;
	printf(K A LIST A K "\n");
	while (list)
	{
		printf("[%3d] [len = %3d] [type = %d] " GREEN "[" RESET "%s" GREEN "]" \
			RESET "\n", i, list->line_size, list->type, list->line);
		i++;
		list = list->next;
	}
	printf("\n");
}

void	print_data(t_data *data)
{
	printf(K A GAME A K "\n");
	printf("North texture path: %s\n", data->north_texture);
	printf("South texture path: %s\n", data->south_texture);
	printf("West texture path: %s\n", data->west_texture);
	printf("East texture path: %s\n", data->east_texture);
	printf("Floor RGB color: %x\n", data->floor_rgb);
	printf("Ceiling RGB color: %x\n", data->ceiling_rgb);
}

void	print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (map[y][x] == '1')
				printf(RED "%c" RESET, map[y][x]);
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' \
				|| map[y][x] == 'E')
				printf(YELLOW "%c" RESET, map[y][x]);
			else
			x++;
		}
		y++;
		printf("\n");
	}
	printf("\n");
}
