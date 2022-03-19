/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/19 23:10:04 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	main(void)
{
	char	file[] = "map.cub";
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	while (get_next_line(fd, &line, 0) > 0)
	{
		
	}
	return (EXIT_SUCCESS);
}
