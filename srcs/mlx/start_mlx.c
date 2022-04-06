/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/06 02:05:17 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_min_map(t_mlx *mlx)
{
	int		rayon[60];
	int		x;
	int		r;
	float	ra;
	double	dist[2];

	x = ((r = 0, 0));
	ra = mlx->player[ANGLE] - ((1 * M_PI / 180) * 30);
	while (r < 60)
	{
		if (ra < 0)
			ra += (2 * M_PI);
		else if (ra > 2 * M_PI)
			ra -= (2 * M_PI);
		dist[0] = horizontal_check(mlx, ra);
		dist[1] = vertical_check(mlx, ra);
		if (dist[1] < dist[0])
			rayon[r] = dist[1];
		if (dist[0] < dist[1])
			rayon[r] = dist[0];
		print_3d(mlx, rayon[r], ra, &x);
		ra += 1 * M_PI / 180;
		r++;
	}
}

/**
 *	@brief	Function start to create the mlx for the graphics
 *
 *	@param	t_tmp	Take in param all the info from the parsing
 *
 *	@return	Return void
 **/
void	start_mlx(char **map)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.map = map;
	find_player_pos(map, &mlx);
	create_texture(&mlx);
	print_min_map(&mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, key_hook, &mlx);
	mlx_hook(mlx.win_ptr, ClientMessage, StructureNotifyMask, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
