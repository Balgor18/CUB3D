/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:19:52 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 14:36:08 by grannou          ###   ########.fr       */
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
	while (tmp)
	{
		if (tmp->type == 0)
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

void	parsing(int argc, char **argv, t_data **data)
{
	int	fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	basic_parsing(argc, argv);
	check_open(argv[1], &fd);
	fill_list(fd, &list);
	check_list_syntax(&list);
	print_list(list);
	check_close(fd, list);
	fill_data(data, list);
	print_data(*data);
	ft_lst_clear(&list);
}