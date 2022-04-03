/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:49:42 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 16:15:22 by grannou          ###   ########.fr       */
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

static int	check_floor_ceiling_syntax(char *str)
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

/*
void	check_player(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		player;

	tmp = *list;
	i = 0;
	player = 0;
	while (tmp)
	{
		if (tmp->type == MAP_LINE)
		{
			while (tmp->line && tmp->line[i])
			{
				if (is_cardinal_char(tmp->line[i]))
					player++;
				i++;
			}
		}
		tmp = tmp->next;
	}
	printf("player nbr = %d\n", player);
	if (player == 0)
		clear_list_exit(list, ZEROPMAP);
	if (player > 1)
		clear_list_exit(list, MULTIPMAP);
}
*/

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
		if (tmp->type == TEXTURE_LINE && check_cardinal_syntax(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		if (tmp->type == COLOR_LINE && check_floor_ceiling_syntax(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		if (tmp->type == MAP_LINE && is_map_str(tmp->line))
			clear_list_syntax_exit(list, i, tmp->line, WCHARMAP);
		i++;
		tmp = tmp->next;
	}
	check_last_element(list);
	// check_map(list)
	// check_player(list);
}
