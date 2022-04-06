/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:50:57 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/06 04:05:39 by fcatinau         ###   ########.fr       */
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
		printf("---------------\n");
		printf("distH = %f\ndistV = %f\n", dist[0], dist[1]);
		printf("rayon[r] = %d\n", rayon[r]);
		print_3d(mlx, rayon[r], ra, &x);
		ra += 1 * M_PI / 180;
		r++;
	}
}

/**
 *	@brief	Function start to create the mlx for the graphics
 *
 *	@param	t_data	Take in param all the info from the parsing
 *
 *	@return	Return void
 **/
void	start_mlx(t_data *data)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.data = data;
	find_player_pos(data->map, &mlx);
	create_texture(&mlx);
	if (!mlx.mlx_ptr)
		return;
	print_min_map(&mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, key_hook, &mlx);
	mlx_hook(mlx.win_ptr, ClientMessage, StructureNotifyMask, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
