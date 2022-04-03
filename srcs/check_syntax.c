/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:49:42 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 18:07:56 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_cardinal_syntax(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0 \
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	check_fc_syntax(char *str)
{
	if ((ft_strncmp(str, "F ", 2) != 0) && (ft_strncmp(str, "C ", 2) != 0))
		return (EXIT_FAILURE);
	str++;
	while (*str)
	{
		if (!is_digit(*str) && *str != ' ' && *str != ',')
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}

static void	check_last_element(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (is_map_str(tmp->line))
		clear_list_syntax_exit(list, i, tmp->line, ENDFILE);
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
		if (tmp->type == ERROR_LINE)
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		else if (tmp->type == TEXTURE_LINE && check_cardinal_syntax(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		else if (tmp->type == COLOR_LINE && check_fc_syntax(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		else if (tmp->type == MAP_LINE && is_map_str(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, WCHARMAP);
		i++;
		tmp = tmp->next;
	}
	check_last_element(list);
}

void	check_splitted_map(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == EMPTY_LINE)
			clear_list_syntax_exit(list, i, tmp->line, SPLITMAP);
		i++;
		tmp = tmp->next;
	}
}
