/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:10:45 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/06 19:01:21 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_3d(t_mlx *mlx, int rayon, double ra, int *x)
{
	double	ca;
	float	lineh;
	float	lineo;

	ca = mlx->player[ANGLE] - ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	rayon = rayon * cos(ca);
	lineh = (mlx->data->map_height * mlx->data->map_width) * HEIGHT / rayon;
	if (lineh > HEIGHT)
		lineh = HEIGHT;
	lineo = (HEIGHT / 2) - lineh / 2;
	mlx_print_line(mlx, (int [2]){*x, lineo},
		(int [2]){*x, lineh + lineo}, 0x00FF0000);
	*x += 1;
}
