/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:00:22 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/08 16:44:46 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define X 0

static double	horizontal_while(t_mlx *mlx, double ray[2], double offset[2]
		, double end_pos[2])
{
	int		map[2];
	int		dof;

	dof = 0;
	while (dof < mlx->data->map_height)
	{
		map[X] = (int)(ray[X]) >> 6;
		map[1] = (int)(ray[1]) >> 6;
		if (0 <= map[1] && map[1] < mlx->data->map_height && 0 <= map[X]
			&& map[X] < (int)ft_strlen(mlx->data->map[map[1]])
			&& mlx->data->map[map[1]][map[X]] == '1')
			return (end_pos[X] = ray[X], end_pos[1] = ray[1]
				, dist(mlx->player[X_PIXEL], mlx->player[Y_PIXEL],
					ray[X], ray[1]));
		else
		{
			ray[X] += offset[X];
			ray[1] += offset[1];
			dof++;
		}
	}
	return (1000000);
}

double	horizontal_check(t_mlx *mlx, double ra, double end_pos[2])
{
	double	ray[2];
	double	offset[2];
	float	atan;

	atan = -1 / tan(ra);
	if (ra < M_PI)
	{
		ray[1] = (((int)mlx->player[Y_PIXEL] >> 6) << 6) - 0.0002;
		ray[X] = (mlx->player[Y_PIXEL] - ray[1]) * atan + mlx->player[X_PIXEL];
		offset[1] = -64;
		offset[X] = -offset[1] * atan;
	}
	if (ra > M_PI)
	{
		ray[1] = (((int)mlx->player[Y_PIXEL] >> 6) << 6) + 64;
		ray[X] = (mlx->player[Y_PIXEL] - ray[1]) * atan + mlx->player[X_PIXEL];
		offset[1] = 64;
		offset[X] = -offset[1] * atan;
	}
	if (ra == 0 || ra == M_PI)
		return (1000000);
	return (horizontal_while(mlx, ray, offset, end_pos));
}
