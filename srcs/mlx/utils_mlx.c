/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:59:09 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/06 03:21:12 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define X 0

double	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

static void	__init0(int dist[2], int ori[2], int const a[2], int const b[2])
{
	dist[X] = abs(b[X] - a[X]);
	dist[1] = -abs(b[1] - a[1]);
	ori[X] = -(a[X] > b[X]) | 1;
	ori[1] = -(a[1] > b[1]) | 1;
}

static void	__init1(int err[2], int const dist[2], int c[2], int const a[2])
{
	err[0] = dist[X] + dist[1];
	c[X] = a[X];
	c[1] = a[1];
}

void	mlx_print_line(t_mlx *mlx, int const a[2], int const b[2],
	int const color)
{
	int dist[2], \
ori[2], c[2], err[2];
	__init0(dist, ori, a, b);
	__init1(err, dist, c, a);
	while (42)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c[X], c[1], color);
		if (c[X] == b[X] && c[1] == b[1])
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= dist[1])
		{
			if (c[X] == b[X])
				break ;
			err[0] = err[0] + dist[1];
			c[X] = c[X] + ori[X];
		}
		if (err[1] <= dist[X])
		{
			if (c[1] == b[1])
				break ;
			err[0] = err[0] + dist[X];
			c[1] = c[1] + ori[1];
		}
	}
}
