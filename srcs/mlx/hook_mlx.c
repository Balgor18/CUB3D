/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 05:17:02 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/08 21:31:57 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifdef X
# undef X
#endif

#ifdef Y
# undef Y
#endif

#define X 0
#define Y 1

static void	check_player_and_move(t_mlx *mlx, char move, double newpos[2])
{
	double	dist[2];

	dist[X] = cos(mlx->player[ANGLE]) * 5;
	dist[Y] = sin(mlx->player[ANGLE]) * 5;
	if (move == 'H')
		newpos[X] = ((newpos[Y] = mlx->player[Y_POS] - (0.005f * dist[Y]),
					mlx->player[X_POS] - (0.005f * dist[X])));
	else if (move == 'B')
		newpos[X] = ((newpos[Y] = mlx->player[Y_POS] + (0.005f * dist[Y]),
					mlx->player[X_POS] + (0.005f * dist[X])));
	else if (move == 'G')
		newpos[X] = ((newpos[Y] = mlx->player[Y_POS] + (0.005f * dist[X]),
					mlx->player[X_POS] - (0.005f * dist[Y])));
	else if (move == 'D')
		newpos[X] = ((newpos[Y] = mlx->player[Y_POS] - (0.005f * dist[X]),
					mlx->player[X_POS] + (0.005f * dist[Y])));
	if (newpos[Y] == -1
		|| mlx->data->map[(int)newpos[Y]][(int)newpos[X]] == '1')
		return ;
	mlx->player[X_POS] = newpos[X];
	mlx->player[Y_POS] = newpos[Y];
	return ;
}

/**
 * @brief modif value of the player when he press a touch
 *
 * @param mlx struct mlx
 * @param move value of the player move
 * @param t a Array of 2 with the value of t[0] = -1f & t[1] = -1f
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
	mlx->player[X_PIXEL] = (mlx->player[X_POS] * 64);
	mlx->player[Y_PIXEL] = (mlx->player[Y_POS] * 64);
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
