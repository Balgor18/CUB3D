/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:30:13 by grannou           #+#    #+#             */
/*   Updated: 2022/03/25 19:12:38 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_extension(char *str, char *ext)
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

static void	check_argc(int argc, char **argv)
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

void	fill_data(t_data **data, t_list *list)
{
	(void)data;
	(void)list;
}

/*
PARSING TO DO LIST
check que pas plus que 4 textures et une de chaque OK
check texture manquante / color maquante OK
pas plus de 2 colors lines et une de chaque OK
que les cardinaux aient 2 chars OK
que les colors aient un seul char OK
que les couleurs soient entre 0 et 255 inclus
que les couleurs soient separees par des virgules
qu'il y ait 3 nombres de couleurs, pas plus pas moins
verif que la map soit le dernier element
-> split sur virgule puis trim whitespaces
verif ouverture des textures
*/

/**
	@brief parse the map file. check the extension, open, syntax, dupplicates,
	values and fill data if correct to send to mlx

	@param argc main's argument count
	@param argv main's array of argument's strings
	@param data structure with all infos parsed in map file
	@return nothing
**/
void	parsing(int argc, char **argv, t_data **data)
{
	int		fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	check_argc(argc, argv);
	check_open(argv[1], &fd);
	fill_list(fd, &list);
	check_list_syntax(&list);
	check_duplicates(&list);

	print_list(list);
	check_close(fd, list);
	fill_data(data, list);
	print_data(*data);
	ft_lst_clear(&list);
}
