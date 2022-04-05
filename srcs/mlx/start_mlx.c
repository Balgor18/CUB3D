/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/05 05:04:42 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_min_map(t_mlx *mlx)
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
		print_3d(mlx, rayon[r], ra, &x);
		ra += 1 * M_PI / 180;
		r++;
	}
}

/**
 * @brief modif value of the player when he press a touch
 *
 * @param mlx struct mlx
 * @param move value of the player move
 * @param t a Array of 2 with the value of t[0] = 0.1f & t[1] = -0.1f
 *
 * @return void
 */
static void	player_move(t_mlx *mlx, char move, double t[2])
{
	double	player[2][2];

	if (move == 'R' || move == 'L')
	{
		mlx->player[ANGLE] += *(double *)ft_ternary(move == 'R', &t[0], &t[1]);
		if (mlx->player[ANGLE] < 0)
			mlx->player[ANGLE] += 2 * M_PI;
		else if (mlx->player[ANGLE] > 2 * M_PI)
			mlx->player[ANGLE] -= 2 * M_PI;
		mlx->delta[0] = cos(mlx->player[ANGLE]) * 5;
		mlx->delta[1] = sin(mlx->player[ANGLE]) * 5;
	}
	player[0][0] = 0.015f * mlx->delta[0];
	player[0][1] = 0.015f * mlx->delta[1];
	player[1][0] = -0.015f * mlx->delta[0];
	player[1][1] = -0.015f * mlx->delta[1];
	if (move == 'U' || move == 'D')
	{
		mlx->player[Y_POS] += *(double *)ft_ternary(move == 'U', &player[1][1],
				&player[0][1]);
		mlx->player[X_POS] += *(double *)ft_ternary(move == 'U', &player[1][0],
				&player[0][0]);
		mlx->player[X_PIXEL] = (mlx->player[X_POS] * 64) + 40;
		mlx->player[Y_PIXEL] = (mlx->player[Y_POS] * 64) + 40;
	}
}

static int	key_hook(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		free_mlx(mlx);
		exit(0);
	}
	else if (key == D || key == RIGHT)
		player_move(mlx, 'R', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == A || key == Q || key == LEFT)
		player_move(mlx, 'L', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == S || key == DOWN)
		player_move(mlx, 'D', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == W || key == Z || key == UP)
		player_move(mlx, 'U', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	print_min_map(mlx);
	return (0);
}

static int	ft_close(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

/**
	@brief	Function start to create the mlx for the graphics

	@param	t_tmp	Take in param all the info from the parsing

	@return	Return void
 **/
void	start_mlx(char **map)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.map = map;
	find_player_pos(map, &mlx);
	create_texture(&mlx);
	print_min_map(&mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_hook, &mlx);
	mlx_hook(mlx.win_ptr, 33, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
