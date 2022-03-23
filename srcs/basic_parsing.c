/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:19:52 by grannou           #+#    #+#             */
/*   Updated: 2022/03/23 05:02:20 by grannou          ###   ########.fr       */
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

// PASSING INT TAB ADDRESS DOES NOT WORK
/*
void	check_cardinal_duplicates(t_list **list, int *infos, char *str, int i)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		printf("infos[NORTH] = %d\n", infos[NORTH]);
		infos[NORTH] += 1;
		printf("infos[NORTH] = %d\n", infos[NORTH]);
		if (infos[NORTH] > 1)
			clear_list_syntax_exit(list, i, str, DUPNO);
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		infos[SOUTH] += 1;
		if (infos[SOUTH] > 1)
			clear_list_syntax_exit(list, i, str, DUPSO);
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		infos[WEST] += 1;
		if (infos[WEST] > 1)
			clear_list_syntax_exit(list, i, str, DUPWE);
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		infos[EAST] += 1;
		if (infos[EAST] > 1)
			clear_list_syntax_exit(list, i, str, DUPEA);
	}
}

void	check_color_duplicates(t_list **list, int *infos, char *str, int i)
{
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		infos[FLOOR] += 1;
		if (infos[FLOOR] > 1)
			clear_list_syntax_exit(list, i, str, DUPF);
	}
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		infos[CEILING] += 1;
		if (infos[CEILING] > 1)
			clear_list_syntax_exit(list, i, str, DUPC);
	}
}

void	check_duplicates(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		infos[6];

	tmp = *list;
	i = 0;
	infos[NORTH] = 0;
	infos[SOUTH] = 0;
	infos[WEST] = 0;
	infos[EAST] = 0;
	infos[FLOOR] = 0;
	infos[CEILING] = 0;
	while (tmp)
	{
		if (tmp->type == 2)
			check_cardinal_duplicates(list, &infos[6], tmp->line, i);
		if (tmp->type == 3)
			check_color_duplicates(list, &infos[6], tmp->line, i);
		i++;
		tmp = tmp->next;
	}
}
*/

// beofre norme
void	check_duplicates(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		infos[6];

	tmp = *list;
	i = 0;
	infos[NORTH] = 0;
	infos[SOUTH] = 0;
	infos[WEST] = 0;
	infos[EAST] = 0;
	infos[FLOOR] = 0;
	infos[CEILING] = 0;
	while (tmp)
	{
		if (tmp->type == 2 && (ft_strncmp(tmp->line, "NO ", 3) == 0))
		{
			infos[NORTH] += 1;
			if (infos[NORTH] > 1)
				clear_list_syntax_exit(list, i, tmp->line, DUPNO);
		}
		else if (tmp->type == 2 && (ft_strncmp(tmp->line, "SO ", 3) == 0))
		{
			infos[SOUTH] += 1;
			if (infos[SOUTH] > 1)
				clear_list_syntax_exit(list, i, tmp->line, DUPSO);
		}
		else if (tmp->type == 2 && (ft_strncmp(tmp->line, "WE ", 3) == 0))
		{
			infos[WEST] += 1;
			if (infos[WEST] > 1)
				clear_list_syntax_exit(list, i, tmp->line, DUPWE);
		}
		else if (tmp->type == 2 && (ft_strncmp(tmp->line, "EA ", 3) == 0))
		{
			infos[EAST] += 1;
			if (infos[EAST] > 1)
				clear_list_syntax_exit(list, i, tmp->line, DUPEA);
		}
		else if (tmp->type == 3 && (ft_strncmp(tmp->line, "F ", 2) == 0))
		{
			infos[FLOOR] += 1;
			if (infos[FLOOR] > 1)
				clear_list_syntax_exit(list, i, tmp->line, DUPF);
		}
		else if (tmp->type == 3 && (ft_strncmp(tmp->line, "C ", 2) == 0))
		{
			infos[CEILING] += 1;
			if (infos[CEILING] > 1)
				clear_list_syntax_exit(list, i, tmp->line, DUPC);
		}
		i++;
		tmp = tmp->next;
	}
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

void	parsing(int argc, char **argv, t_data **data)
{
	int		fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	basic_parsing(argc, argv);
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
