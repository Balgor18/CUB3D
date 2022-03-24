/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:49:42 by grannou           #+#    #+#             */
/*   Updated: 2022/03/24 20:50:30 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_cardinal_syntax(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0 \
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	check_floor_ceiling_syntax(char *str)
{
	if ((ft_strncmp(str, "F ", 2) == 0) || (ft_strncmp(str, "C ", 2) == 0))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
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
