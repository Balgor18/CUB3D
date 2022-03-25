/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:23:18 by grannou           #+#    #+#             */
/*   Updated: 2022/03/25 19:28:29 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_cardinal_duplicates(t_list **list, int *dup, char *str, int i)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		dup[NORTH] += 1;
		if (dup[NORTH] > 1)
			clear_list_syntax_exit(list, i, str, DUPNO);
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		dup[SOUTH] += 1;
		if (dup[SOUTH] > 1)
			clear_list_syntax_exit(list, i, str, DUPSO);
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		dup[WEST] += 1;
		if (dup[WEST] > 1)
			clear_list_syntax_exit(list, i, str, DUPWE);
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		dup[EAST] += 1;
		if (dup[EAST] > 1)
			clear_list_syntax_exit(list, i, str, DUPEA);
	}
}

static void	check_color_duplicates(t_list **list, int *dup, char *str, int i)
{
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		dup[FLOOR] += 1;
		if (dup[FLOOR] > 1)
			clear_list_syntax_exit(list, i, str, DUPF);
	}
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		dup[CEILING] += 1;
		if (dup[CEILING] > 1)
			clear_list_syntax_exit(list, i, str, DUPC);
	}
}

static void	check_missing_lines(t_list **list, int *dup)
{
	if (dup[NORTH] == 0)
		clear_list_exit(list, MISSNO);
	else if (dup[SOUTH] == 0)
		clear_list_exit(list, MISSSO);
	else if (dup[WEST] == 0)
		clear_list_exit(list, MISSWE);
	else if (dup[EAST] == 0)
		clear_list_exit(list, MISSEA);
	else if (dup[FLOOR] == 0)
		clear_list_exit(list, MISSF);
	else if (dup[CEILING] == 0)
		clear_list_exit(list, MISSC);
}

void	check_list_duplicates(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		dup[6];

	tmp = *list;
	i = 0;
	bzero_int_tab(dup, 6, 0);
	while (tmp)
	{
		if (tmp->type == 2)
			check_cardinal_duplicates(list, dup, tmp->line, i);
		if (tmp->type == 3)
			check_color_duplicates(list, dup, tmp->line, i);
		i++;
		tmp = tmp->next;
	}
	check_missing_lines(list, dup);
}
