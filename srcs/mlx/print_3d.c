/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:10:45 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/09 04:06:17 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef void		(*t_fct)(
	t_img *const img[2],
	t_rayon const *const rayon,
	float i[4]);

static t_fct const	g_fct[] = {
	print_nord,
	print_south,
	print_west,
	print_east};

void	fill_floor_wall_and_ceiling(t_mlx *const mlx,
	t_rayon const *const rayon,
	float const lineh, int const x)
{
	const float	ceil_h = (HEIGHT - lineh) / 2;
	float		i;

	i = 0;
	while (i < ceil_h)
	{
		mlx->pict[IMAGE].addr[x + (int)i * WIDTH] = mlx->data->ceiling_rgb;
		i++;
	}
	g_fct[rayon->type]((t_img *[]){&mlx->pict[IMAGE], &mlx->pict[rayon->type]},
			rayon, (float []){x, i, lineh, ceil_h});
	i = lineh + ceil_h;
	while (i < HEIGHT)
	{
		mlx->pict[IMAGE].addr[x + (int)i * WIDTH] = mlx->data->floor_rgb;
		i++;
	}
}

void	print_3d(t_mlx *const mlx, t_rayon *const rayon, double ra, int *x)
{
	double	ca;
	float	lineh;

	ca = mlx->player[ANGLE] - ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	rayon->dist = rayon->dist * cos(ca);
	lineh = (mlx->data->map_height * mlx->data->map_width)
		* HEIGHT / rayon->dist;
	fill_floor_wall_and_ceiling(mlx, rayon, lineh, *x);
	*x += 1;
}
