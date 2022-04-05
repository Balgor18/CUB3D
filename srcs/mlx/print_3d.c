/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:10:45 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/05 04:22:02 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_3d(t_mlx *mlx, int rayon, double ra, int *x)
{
	int		height;
	double	ca;
	float	lineh;
	float	lineo;

	height = 0;
	ca = mlx->player[ANGLE] - ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	rayon = rayon * cos(ca);
	lineh = (6 * 16) * 384 / rayon;
	if (lineh > 384)
		lineh = 384;
	lineo = 192 - lineh / 2;
	while (height != ((64 * 6) / 16))
	{
		mlx_print_line(mlx, (int [2]){*x, lineo},
			(int [2]){*x, lineh + lineo}, 0x00FF0000);
		*x += 1;
		height++;
	}
}
