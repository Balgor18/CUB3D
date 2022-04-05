/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:00:22 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/05 05:12:15 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define X 0
#define Y 1

static double	horizontal_while(t_mlx *mlx, double ray[2], double offset[2])
{
	int		map[2];
	int		dof;

	dof = 0;
	while (dof < 6) // modif the value
	{
		map[X] = (int)(ray[X]) >> 6;
		map[Y] = (int)(ray[Y]) >> 6;
		if (0 <= map[Y] && map[Y] < 6 && 0 <= map[X]
			&& map[X] < (int)ft_strlen(mlx->map[map[Y]])
			&& mlx->map[map[Y]][map[X]] == '1')
			return (dist(mlx->player[X_PIXEL], mlx->player[Y_PIXEL],
					ray[X], ray[Y]));
		else
		{
			ray[X] += offset[X];
			ray[Y] += offset[Y];
			dof++;
		}
	}
	return (1000000);
}

double	horizontal_check(t_mlx *mlx, double ra)
{
	double	ray[2];
	double	offset[2];
	float	atan;

	atan = -1 / tan(ra);
	if (ra < M_PI)
	{
		ray[Y] = (((int)mlx->player[Y_PIXEL] >> 6) << 6) - 0.0002;
		ray[X] = (mlx->player[Y_PIXEL] - ray[Y]) * atan + mlx->player[X_PIXEL];
		offset[Y] = -64;
		offset[X] = -offset[Y] * atan;
	}
	if (ra > M_PI)
	{
		ray[Y] = (((int)mlx->player[Y_PIXEL] >> 6) << 6) + 64;
		ray[X] = (mlx->player[Y_PIXEL] - ray[Y]) * atan + mlx->player[X_PIXEL];
		offset[Y] = 64;
		offset[X] = -offset[Y] * atan;
	}
	if (ra == 0 || ra == M_PI)
		return (1000000);
	return (horizontal_while(mlx, ray, offset));
}
