/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:58:46 by grannou           #+#    #+#             */
/*   Updated: 2022/04/09 19:27:33 by grannou          ###   ########.fr       */
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
	printf(KYU BIE "%s" BIE KYU, msg);
	printf("[%d] " YELLOW "[%s]" RESET"\n", i, line);
	ft_lst_clear(list);
	exit(EXIT_FAILURE);
}

void	clear_data_syntax_exit(t_data **data, int i, char *line, char *msg)
{
	write(2, "Error\n", 6);
	printf(KYU BIE "%s" BIE KYU, msg);
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

void	clear_data_nclosedmap_exit(t_data **data, int i, char *msg)
{
	int	j;

	j = 0;
	write(2, "Error\n", 6);
	printf(KYU BIE "%s" BIE KYU, msg);
	while (j < (*data)->map_height)
	{
		if ((j == i - 1) && (i - 1 > 0))
			printf("[%d] " YELLOW "[%s]" RESET"\n", j, (*data)->map[i - 1]);
		else if (j == i)
			printf("[%d] " RED "[%s]" RESET"\n", j, (*data)->map[i]);
		else if ((j == i + 1) && (i + 1 < (*data)->map_height))
			printf("[%d] " YELLOW "[%s]" RESET"\n", j, (*data)->map[i + 1]);
		else
			printf("[%d] [%s]\n", j, (*data)->map[j]);
		j++;
	}
	clear_data(data);
	exit(EXIT_FAILURE);
}
