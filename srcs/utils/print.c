/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:23 by grannou           #+#    #+#             */
/*   Updated: 2022/04/08 17:12:43 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	printf(K ALED "%s" ALED K, msg);
	exit(EXIT_FAILURE);
}

void	print_list(t_list *list)
{
	int	i;

	i = 0;
	printf(K ALED LIST ALED K "\n");
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
	printf(K ALED GAME ALED K "\n");
	printf("North texture path : %s\n", data->north_texture);
	printf("South texture path : %s\n", data->south_texture);
	printf("West texture path  : %s\n", data->west_texture);
	printf("East texture path  : %s\n", data->east_texture);
	printf("Floor RGB color    : %d\n", data->floor_rgb);
	printf("Ceiling RGB color  : %d\n", data->ceiling_rgb);
	printf("Player x position  : %d\n", data->player_x);
	printf("Player y position  : %d\n", data->player_y);
	printf("Player direction   : %c\n", data->player_dir);
	printf("Player dir radian  : %f\n\n", data->player_dir_radian);
	print_map(data->map);
}

	// printf("In print map\n");
void	print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	if (!map)
		return ;
	while (map[y])
	{
		printf(GREEN "[" RESET);
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				printf(RED "%c" RESET, map[y][x]);
			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' \
				|| map[y][x] == 'E')
				printf(YELLOW "%c" RESET, map[y][x]);
			else
				printf("%c", map[y][x]);
			x++;
		}
		printf(GREEN "]" RESET "\n");
		y++;
	}
	printf("\n");
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("[%d]: [%s]\n", i, array[i]);
		i++;
	}
}
