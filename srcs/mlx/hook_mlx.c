/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 05:17:02 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/05 21:55:59 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	int		ra;
	int		pos[2];

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
	if (move == 'H' || move == 'B')
	{
		mlx->player[Y_POS] += *(double *)ft_ternary(move == 'H', &player[1][1],
				&player[0][1]);
		mlx->player[X_POS] += *(double *)ft_ternary(move == 'H', &player[1][0],
				&player[0][0]);
		mlx->player[X_PIXEL] = (mlx->player[X_POS] * 64) + 40;
		mlx->player[Y_PIXEL] = (mlx->player[Y_POS] * 64) + 40;
	}

	if (move == 'G' || move == 'D')
	{
		if (move == 'G')
			ra = mlx->player[ANGLE] - (M_PI / 2);
		if (move == 'D')
			ra = mlx->player[ANGLE] - (3 * M_PI / 2);
		if (ra < 0)
			ra += 2 * M_PI;
		else if (ra > 2 * M_PI)
			ra -= 2 * M_PI;
		pos[0] = cos(mlx->player[ANGLE]) * 5;//X
		pos[1] = sin(mlx->player[ANGLE]) * 5;
		if (move == 'G')
		{
			mlx->player[X_POS] -= 0.01 * pos[1];
			mlx->player[Y_POS] += 0.01 * pos[0];
		}

		if (move == 'D')
		{
			mlx->player[X_POS] += 0.01 * pos[1];
			mlx->player[Y_POS] -= 0.01 * pos[0];
		}
		mlx->player[X_PIXEL] = (mlx->player[X_POS] * 64) + 40;
		mlx->player[Y_PIXEL] = (mlx->player[Y_POS] * 64) + 40;
	}
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		free_mlx(mlx);
		exit(0);
	}
	else if (key == D)
		player_move(mlx, 'D', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == A)
		player_move(mlx, 'G', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == S)
		player_move(mlx, 'B', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == W)
		player_move(mlx, 'H', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == LEFT)
		player_move(mlx, 'L', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == RIGHT)
		player_move(mlx, 'R', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	// else if (key == D || key == RIGHT)
	// 	player_move(mlx, 'R', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	// else if (key == A || key == Q || key == LEFT)
	// 	player_move(mlx, 'L', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	// else if (key == S || key == DOWN)
	// 	player_move(mlx, 'D', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	// else if (key == W || key == Z || key == UP)
	// 	player_move(mlx, 'U', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	print_min_map(mlx);
	return (0);
}

int	ft_close(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}
