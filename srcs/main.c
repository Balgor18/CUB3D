/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 09:21:47 by grannou          ###   ########.fr       */
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

static void	print_struct(t_tmp *file)
{
	while (file)
	{
		printf("%s\n", file->line);
		file = file->next;
	}
}

static void	free_tmp(t_tmp *file)
{
	t_tmp	*tmp;

	while (file)
	{
		tmp = file;
		file = file->next;
		free(tmp->line);
		free(tmp);
	}
}

int	main(void)
{
	char	*file_name;
	char	*line;
	int		fd;
	t_tmp	*file;

	file = NULL;
	file_name = "map.cub";
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	while (get_next_line(fd, &line, 0) > 0)
		create_tmp(&file, line);
	get_next_line(fd, &line, 1);
	free(line);
	close(fd);
	print_struct(file);
	start_mlx(file);
	free_tmp(file);
	return (EXIT_SUCCESS);
}
