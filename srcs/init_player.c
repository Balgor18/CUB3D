/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:25:33 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/08 21:35:06 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_player(char c, double *angle)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			*angle = M_PI / 2;
		else if (c == 'S')
			*angle = 1.5 * M_PI;
		else if (c == 'E')
			*angle = M_PI;
		else if (c == 'W')
			*angle = 0;
		return (true);
	}
	return (false);
}

static void	init_player(t_mlx *mlx, int *pos)
{
	mlx->player[X_POS] = pos[0] + 0.5f;
	mlx->player[Y_POS] = pos[1] + 0.5f;
	mlx->player[X_PIXEL] = mlx->player[X_POS] * 64;
	mlx->player[Y_PIXEL] = mlx->player[Y_POS] * 64;
	mlx->delta[0] = cos(mlx->player[ANGLE]) * 5;
	mlx->delta[1] = sin(mlx->player[ANGLE]) * 5;
}

/**
 * @brief	Function find the player position
 * 			fill the struct with the value
 *
 * @param	char**	to parse the map and find the player
 * @param	t_mlx	for fill the value of the player
 *
 * @return	return void
**/
void	find_player_pos(char **tmp, t_mlx *mlx)
{
	int		pos[2];
	char	*s;
	char	**tmpb;

	tmpb = tmp;
	pos[1] = 0;
	while (tmp)
	{
		pos[0] = 0;
		s = *tmp;
		while (*s)
		{
			if (is_player(*s, &mlx->player[ANGLE]))
			{
				*s = '0';
				init_player(mlx, pos);
				return ;
			}
			pos[0]++;
			s++;
		}
		pos[1]++;
		tmp++;
	}
	tmp = tmpb;
}
