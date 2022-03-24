/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:33:22 by grannou           #+#    #+#             */
/*   Updated: 2022/03/24 02:35:47 by grannou          ###   ########.fr       */
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

void	check_argc(int argc, char **argv)
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

static void	check_cardinal_duplicates(t_list **list, int *dup, char *str, int i)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		dup[NORTH] += 1;
		if (*(dup + NORTH) > 1)
			clear_list_syntax_exit(list, i, str, DUPNO);
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		dup[SOUTH] += 1;
		if (*(dup + SOUTH) > 1)
			clear_list_syntax_exit(list, i, str, DUPSO);
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		dup[WEST] += 1;
		if (*(dup + WEST) > 1)
			clear_list_syntax_exit(list, i, str, DUPWE);
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		dup[EAST] += 1;
		if (*(dup + EAST) > 1)
			clear_list_syntax_exit(list, i, str, DUPEA);
	}
}

static void	check_color_duplicates(t_list **list, int *dup, char *str, int i)
{
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		dup[FLOOR] += 1;
		if (*(dup + FLOOR) > 1)
			clear_list_syntax_exit(list, i, str, DUPF);
	}
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		dup[CEILING] += 1;
		if (*(dup + CEILING) > 1)
			clear_list_syntax_exit(list, i, str, DUPC);
	}
}

void	check_duplicates(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		dup[6];

	tmp = *list;
	i = 0;
	dup[NORTH] = 0;
	dup[SOUTH] = 0;
	dup[WEST] = 0;
	dup[EAST] = 0;
	dup[FLOOR] = 0;
	dup[CEILING] = 0;
	while (tmp)
	{
		if (tmp->type == 2)
			check_cardinal_duplicates(list, dup, tmp->line, i);
		if (tmp->type == 3)
			check_color_duplicates(list, dup, tmp->line, i);
		i++;
		tmp = tmp->next;
	}
}
