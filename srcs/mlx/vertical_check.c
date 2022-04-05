/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:35:26 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/05 04:36:54 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define X 0
#define Y 1

static double	vertical_while(t_mlx *mlx, double rayon[2], double offset[2])
{
	int		map[2];
	int		dof;

	dof = 0;
	map[Y] = 0;
	while (map[Y] >= 0 && map[Y] < 6 && dof < (int)ft_strlen(mlx->map[map[Y]])) //modif value
	{
		map[X] = (int)(rayon[X]) >> 6;
		map[Y] = (int)(rayon[Y]) >> 6;
		if (map[Y] < 0 && map[X] < 0)
			break ;
		if (0 <= map[Y] && map[Y] < 6 && 0 <= map[X]
			&& map[X] < (int)ft_strlen(mlx->map[map[Y]])
			&& mlx->map[map[Y]][map[X]] == '1')
			return (dist(mlx->player[X_PIXEL], mlx->player[Y_PIXEL]
					, rayon[X], rayon[Y]));
		else
		{
			rayon[X] += offset[X];
			rayon[Y] += offset[Y];
			dof++;
		}
	}
	return (1000000);
}

double	vertical_check(t_mlx *mlx, double ra)
{
	double	rayon[2];
	double	offset[2];
	double	ntan;

	ntan = -tan(ra);
	if ((M_PI / 2) < ra && ra < (3 * M_PI / 2))
	{
		rayon[X] = (((int)mlx->player[X_PIXEL] >> 6) << 6) + 64;
		rayon[Y] = (mlx->player[X_PIXEL] - rayon[X]) * ntan;
		rayon[Y] += mlx->player[Y_PIXEL];
		offset[X] = 64;
		offset[Y] = -offset[X] * ntan;
	}
	if (ra < (M_PI / 2) || (3 * M_PI / 2) < ra)
	{
		rayon[X] = (((int)mlx->player[X_PIXEL] >> 6) << 6) - 0.0002;
		rayon[Y] = (mlx->player[X_PIXEL] - rayon[X]) * ntan;
		rayon[Y] += mlx->player[Y_PIXEL];
		offset[X] = -64;
		offset[Y] = -offset[X] * ntan;
	}
	if (ra == (M_PI / 2) || ra == (3 * M_PI / 2))
		return (1000000);
	return (vertical_while(mlx, rayon, offset));
}
