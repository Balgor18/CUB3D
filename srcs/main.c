/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:57:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 09:57:10 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	printf(K A "%s" A K, msg);
	exit (EXIT_FAILURE);
}

void	basic_parsing(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
		printf("Go to parsing\n");
	else if (argc == 1)
		exit_error(MARG);
	else if (argc > 2)
		exit_error(TMARG);
}

int	main(int argc, char **argv)
{
	basic_parsing(argc, argv);
	return (EXIT_SUCCESS);
}
