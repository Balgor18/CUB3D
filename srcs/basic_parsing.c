/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:19:52 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 11:35:06 by grannou          ###   ########.fr       */
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

void	fill_data(t_data **data)
{
	(void)data;
}

void	parsing(int argc, char **argv, t_data **data)
{
	int	fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	basic_parsing(argc, argv);
	check_open(argv[1], &fd);
	fill_list(fd, &list);
	print_list(list);
	check_close(fd, list);
	fill_data(data);
	print_data(*data);
	ft_lst_clear(&list);
}