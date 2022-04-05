/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:58:46 by grannou           #+#    #+#             */
/*   Updated: 2022/04/05 21:56:38 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_list_exit(t_list **list, char *msg)
{
	ft_lst_clear(list);
	exit_error(msg);
}

void	clear_list_syntax_exit(t_list **list, int i, char *line, char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	printf("[%d] " YELLOW "[%s]" RESET"\n", i, line);
	ft_lst_clear(list);
	exit(EXIT_FAILURE);
}

void	clear_data_syntax_exit(t_data **data, int i, char *line, char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	printf("[%d] " YELLOW "[%s]" RESET"\n", i, line);
	clear_data(data);
	exit(EXIT_FAILURE);
}

void	clear_list_free_line_exit(t_list **list, char *line)
{
	ft_lst_clear(list);
	free(line);
	exit_error(GNLFAIL);
}
