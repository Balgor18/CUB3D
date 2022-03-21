/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 14:14:40 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// 0 = HEIGHT
// 1 = WIDTH;
static void	print_map(t_tmp *file, t_mlx mlx)
{
	int	i[2];

	(void)file;
	(void)mlx;
	(void)i;
	// while ()
}

void	start_mlx(t_tmp *file)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "Test win");
	if (!mlx.win_ptr)
		return (mlx_destroy_display(mlx.mlx_ptr), free(mlx.mlx_ptr));
	print_map(file, mlx);
	mlx_loop(mlx.mlx_ptr);
	// mlx;
}
