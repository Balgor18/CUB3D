/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 05:17:02 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/06 01:46:26 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_player_and_move(t_mlx *mlx, char move, double d[2])
{
	double	pos[2];

	pos[0] = cos(mlx->player[ANGLE]) * 5;
	pos[1] = sin(mlx->player[ANGLE]) * 5;
	if (move == 'H')
		d[0] = ((d[1] = mlx->player[Y_POS] - (0.005f * pos[1]),
					mlx->player[X_POS] - (0.005f * pos[0])));
	else if (move == 'B')
		d[0] = ((d[1] = mlx->player[Y_POS] + (0.005f * pos[1]),
					mlx->player[X_POS] + (0.005f * pos[0])));
	else if (move == 'G')
		d[0] = ((d[1] = mlx->player[Y_POS] + (0.005f * pos[0]),
					mlx->player[X_POS] - (0.005f * pos[1])));
	else if (move == 'D')
		d[0] = ((d[1] = mlx->player[Y_POS] - (0.005f * pos[0]),
					mlx->player[X_POS] + (0.005f * pos[1])));
	printf("-----------------------\n");
	printf("[%f][%f]\n", d[1], d[0]);
	printf("[%d][%d]\n", (int)d[1], (int)d[0]);
	if (d[1] == -1 || mlx->map[(int)d[1]][(int)d[0]] == '1')
		return ;
	mlx->player[X_POS] = d[0];
	mlx->player[Y_POS] = d[1];
	return ;
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
	if (move == 'R' || move == 'L')
	{
		mlx->player[ANGLE] += *(double *)ft_ternary(move == 'R', &t[0], &t[1]);
		if (mlx->player[ANGLE] < 0)
			mlx->player[ANGLE] += 2 * M_PI;
		else if (mlx->player[ANGLE] > 2 * M_PI)
			mlx->player[ANGLE] -= 2 * M_PI;
		mlx->delta[0] = cos(mlx->player[ANGLE]) * 5;
		mlx->delta[1] = sin(mlx->player[ANGLE]) * 5;
		return ;
	}
	if (move == 'H')
		check_player_and_move(mlx, 'H', (double [2]){-1, -1});
	else if (move == 'B')
		check_player_and_move(mlx, 'B', (double [2]){-1, -1});
	else if (move == 'G')
		check_player_and_move(mlx, 'G', (double [2]){-1, -1});
	else if (move == 'D')
		check_player_and_move(mlx, 'D', (double [2]){-1, -1});
	mlx->player[X_PIXEL] = (mlx->player[X_POS] * 64) + 40;
	mlx->player[Y_PIXEL] = (mlx->player[Y_POS] * 64) + 40;
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
