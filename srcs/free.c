/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:58:46 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 11:53:32 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_list_exit(t_list **list, char *msg)
{
	ft_lst_clear(list);
	exit_error(msg);
}

void	clear_list_free_line_exit(t_list **list, char *line)
{
	ft_lst_clear(list);
	free(line);
	exit_error(GNLFAIL);
}
