/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:30:13 by grannou           #+#    #+#             */
/*   Updated: 2022/03/24 20:45:23 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_data(t_data **data, t_list *list)
{
	(void)data;
	(void)list;
}

void	check_list_syntax(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	if (!tmp)
		clear_list_exit(list, EMPTYMAP);
	while (tmp)
	{
		if (tmp->type == 5)
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		if (tmp->type == 2 && check_cardinal_syntax(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		if (tmp->type == 3 && check_floor_ceiling_syntax(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		i++;
		tmp = tmp->next;
	}
}

/*
PARSING TO DO LIST
check que pas plus que 4 textures et une de chaque
pas plus de 2 colors lines et une de chaque
que les cardinaux aient 2 chars
que les colors aient un seul char
que les couleurs soient entre 0 et 255 inclus
que les couleurs soient separees par des virgules
qu'il y ait 3 nombres de couleurs, pas plus pas moins
-> split sur virgule puis trim whitespaces
verif format direct 4 lignes daffillee, au moin une ligne vide
deux lignes couleurs, au moins une ligne vide, puis map
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
