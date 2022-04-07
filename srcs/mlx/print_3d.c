/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:10:45 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/07 04:15:59 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_floor_wall_and_ceiling(t_img *img, t_data *data, float lineh, int const x)
{
	const float ceil_h = (HEIGHT - lineh) / 2;
	float	i;

	i = 0;
	while (i < ceil_h)
	{
		img->addr[x + (int)i * WIDTH] = data->ceiling_rgb;
		i++;
	}
	while (i < lineh + ceil_h)
	{
		img->addr[x + (int)i * WIDTH] = 0x00FF0000;
		i++;
	}
	while (i < HEIGHT)
	{
		img->addr[x + (int)i * WIDTH] = data->floor_rgb;
		i++;
	}
}

void	print_3d(t_mlx *mlx, float dist, double ra, int *x)
{
	double	ca;
	float	lineh;

	ca = mlx->player[ANGLE] - ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	dist = dist * cos(ca);
	lineh = (mlx->data->map_height * mlx->data->map_width) * HEIGHT / dist;
	if (lineh > HEIGHT)
		lineh = HEIGHT;
	fill_floor_wall_and_ceiling(&mlx->pict[IMAGE], mlx->data, lineh, *x);
	// mlx_print_line(mlx, (int [2]){*x, lineo}, (int [2]){*x, lineh + lineo}, 0x00FF0000);
	*x += 1;
}
