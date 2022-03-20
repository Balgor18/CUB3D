/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/20 13:33:00 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	t_tmp	*last_tmp(t_tmp *file)
{
	while (file->next)
	{
		file = file->next;
	}
	return (file);
}

static	void	create_tmp(t_tmp **file, char *add)
{
	t_tmp	*tmp;

	if (!add)
		return ;
	tmp = malloc(sizeof(t_tmp));
	if (!tmp)
		return ;
	tmp->next = NULL;
	tmp->line = add;
	if (!*file)
	{
		*file = tmp;
		return ;
	}
	last_tmp(*file)->next = tmp;
	return ;	
}

static	void	print_struct(t_tmp *file)
{
	while (file)
	{
		printf("%s\n", file->line);
		file = file->next;
	}
}

int	main(void)
{
	char	file_name[] = "map.cub";
	char	*line;
	int		fd;
	t_tmp	*file;

	file = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	while (get_next_line(fd, &line, 0) > 0)
	{
		create_tmp(&file, line);
	}
	print_struct(file);
	return (EXIT_SUCCESS);
}
