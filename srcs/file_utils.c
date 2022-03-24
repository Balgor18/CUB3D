/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:46:10 by grannou           #+#    #+#             */
/*   Updated: 2022/03/24 20:46:18 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_open(char *filename, int *fd)
{
	*fd = open(filename, O_DIRECTORY | O_RDONLY);
	if (*fd != -1)
	{
		close(*fd);
		exit_error (OPENDIRERR);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		exit_error(OPENERR);
}

int	check_close(int fd, t_list *list)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		clear_list_exit(&list, CLOSEERR);
	return (EXIT_SUCCESS);
}
