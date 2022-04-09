/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:35:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/09 20:22:21 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define X 0

static double	vertical_while(t_mlx *mlx, double rayon[2], double *offset
		, double end_pos[2])
{
	int		map[2];
	int		dof;

	dof = 0;
	map[1] = 0;
	while (map[1] >= 0 && map[1] < mlx->data->map_height
		&& dof < ft_strlen(mlx->data->map[map[1]]))
	{
		map[X] = (int)(rayon[X]) >> 6;
		map[1] = (int)(rayon[1]) >> 6;
		if (map[1] < 0 && map[X] < 0)
			break ;
		if (0 <= map[1] && map[1] < mlx->data->map_height && 0 <= map[X]
			&& map[X] < (int)ft_strlen(mlx->data->map[map[1]])
			&& mlx->data->map[map[1]][map[X]] == '1')
			return (end_pos[X] = rayon[X], end_pos[1] = rayon[1]
				, dist(mlx->player[X_PIXEL], mlx->player[Y_PIXEL]
					, rayon[X], rayon[1]));
		else
		{
			rayon[X] += ((rayon[1] += offset[1], offset[X]));
			dof++;
		}
	}
	return (1000000);
}

double	vertical_check(t_mlx *mlx, double ra, double end_pos[2])
{
	double	rayon[2];
	double	offset[2];
	double	ntan;

	ntan = -tan(ra);
	if ((M_PI / 2) < ra && ra < (3 * M_PI / 2))
	{
		rayon[X] = (((int)mlx->player[X_PIXEL] >> 6) << 6) + 64;
		rayon[1] = (mlx->player[X_PIXEL] - rayon[X]) * ntan;
		rayon[1] += mlx->player[Y_PIXEL];
		offset[X] = 64;
		offset[1] = -offset[X] * ntan;
	}
	if (ra < (M_PI / 2) || (3 * M_PI / 2) < ra)
	{
		rayon[X] = (((int)mlx->player[X_PIXEL] >> 6) << 6) - 0.0002;
		rayon[1] = (mlx->player[X_PIXEL] - rayon[X]) * ntan;
		rayon[1] += mlx->player[Y_PIXEL];
		offset[X] = -64;
		offset[1] = -offset[X] * ntan;
	}
	if (ra == (M_PI / 2) || ra == (3 * M_PI / 2))
		return (1000000);
	return (vertical_while(mlx, rayon, offset, end_pos));
}
