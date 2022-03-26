/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/26 14:05:30 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_player(char c, float *angle)
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
		return true;
	}
	return false;
}

// pos[0] = X;
// pos[1] = Y;
static void	find_player_pos(t_tmp *tmp, t_mlx *mlx)
{
	int	pos[2];
	t_tmp	*tmpb;
	char	*s;

	tmpb = tmp;
	pos[1] = 1;
	while (tmp)
	{
		pos[0] = 1;
		s = tmp->line;
		while (*s)
		{
			if (is_player(*s, &mlx->player[ANGLE]))
			{
				*s = '0';
				mlx->player[X_POS] = pos[0];
				mlx->player[Y_POS] = pos[1];
				mlx->delta[0] = cos(mlx->player[ANGLE]);
				mlx->delta[1] = sin(mlx->player[ANGLE]);
				// printf("x = %f | y = %f\n", mlx->delta[0], mlx->delta[1]);
				return ;
			}
			pos[0]++;
			s++;
		}
		pos[1]++;
		tmp = tmp->next;
	}
	tmp = tmpb;
}

static void	xpm_file_and_addr(void *mlx_ptr, t_img *img, int byte)
{
	int	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, 64, 64);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->bits_per_pixel, &img->endian);
	while (i < 4096)
	{
		img->addr[i] = byte;
		i++;
	}
}

static void	xpm_file_and_addr_player(void *mlx_ptr, t_img *img, int byte)
{
	int	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, 16, 16);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->bits_per_pixel, &img->endian);
	while (i < 256)
	{
		img->addr[i] = byte;
		i++;
	}
}

//	i[0] == Y
//	i[1] == X
static void	print_min_map(t_mlx *mlx)
{
	t_tmp *tmp;
	char	*s;
	int		in[2];

	in[0] = 0;
	tmp = mlx->file;
	while (mlx->file)
	{
		s = mlx->file->line;
		in[1] = 0;
		while (*s)
		{
			if (*s == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[WALL].img, in[1], in[0]);
			// else if (*s == '0')
			// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[FLOOR].img, in[1], in[0]);
			s++;
			in[1] += 64;
		}
		in[0] += 64;
		mlx->file = mlx->file->next;
	}
	mlx->file = tmp;
	//player
	float	i[2];

	i[0] = (mlx->player[X_POS] * 64) - 40;
	i[1] = (mlx->player[Y_POS] * 64) - 40;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[PLAYER].img, i[0], i[1]);

	// Juste a direction line

	// float	start_point[2];
	float	end_point[2];
	i[0] += 8;
	i[1] += 8;
	// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i[0], i[1], 0x00FFFF00);

	int		j;
	j = 0;
	// printf("Player :\n\rX = %f\n\rY = %f\n", i[0], i[1]);
	// printf("Delta : \n\rX = %f\n\rY = %f\n", mlx->delta[0], mlx->delta[1]);
	while (j < 400)
	{
		end_point[0] = 0.1 * mlx->delta[0];
		end_point[1] = 0.1 * mlx->delta[1];
		// ----- X -----
		if (mlx->delta[0] > 0)
			end_point[0] *= -j;
		else
			end_point[0] *= -j;

		// ----- Y -----
		if (mlx->delta[1] > 0)
			end_point[1] *= -j;
		else
			end_point[1] *= -j;

		end_point[0] += i[0];
		end_point[1] += i[1];
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, end_point[0], end_point[1], 0x00FFFF00);
		j++;
	}
}

/**
 * @brief	Function create all the texture
 *
 * @param	t_mlx	All the informations we need for create the texture
 *
 * @return	return void
**/
static void	create_texture(t_mlx *mlx)
{
	int		width;
	int		height;

	width = 64 * 16;
	height = 6 * 64;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, "Test win");
	if (!mlx->win_ptr)
		return (free_mlx(mlx));

	xpm_file_and_addr_player(mlx->mlx_ptr, &mlx->pict[PLAYER], 0x0000FF00);
	xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[WALL], 0x000000FF);
	xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[FLOOR], 0x00FFFFFF);
	print_min_map(mlx);
	// add a function for hook
	// xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[CEILING], 0x00000000);
}

void	*ft_ternary(int cond, void *valid_1, void *valid_2)
{
	if (cond)
		return (valid_1);
	return (valid_2);
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
static void	player_move(t_mlx *mlx, char move, float t[2])
{
	if (move == 'R' || move == 'L')
	{
		mlx->player[ANGLE] += *(float *)ft_ternary(move == 'R', (void *)&t[0], (void *)&t[1]);
		if(mlx->player[ANGLE] < 0)
			mlx->player[ANGLE] += 2 * M_PI;
		else if(mlx->player[ANGLE] > 2 * M_PI)
			mlx->player[ANGLE] -= 2 * M_PI;
		mlx->delta[0] = cos(mlx->player[ANGLE]);
		mlx->delta[1] = sin(mlx->player[ANGLE]);
	}
	// else if (move == 'U' || move == 'R')
	// {
	//	 mlx->player[X_POS] += *(float *)ft_ternary(move == 'R', (void *)&t[0], (void *)&t[1]);
	// }

	mlx->player[X_POS] += (move == 'U') ? t[1] * mlx->delta[0] : t[0] * mlx->delta[0];
	mlx->player[Y_POS] += (move == 'U') ? t[1] * mlx->delta[1] : t[0] * mlx->delta[1];
	// else if (move == 'U')
	// {
	// 	mlx->player[Y_POS] -= (0.1 * mlx->delta[1]);
	// 	mlx->player[X_POS] -= (0.1 * mlx->delta[0]);
	// }
	// else if (move == 'D')
	// {
	// 	mlx->player[Y_POS] += (0.1 * mlx->delta[1]);
	// 	mlx->player[X_POS] += (0.1 * mlx->delta[0]);
	// }
}


static int	key_hook(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
	{
		// if (mlx->map.player.move != 0)
		// 	ft_putchar_fd('\n', 1);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		free_mlx(mlx);
		exit(0);
	}
	else if (key == D || key == RIGHT)
		player_move(mlx, 'R', (float [2]){0.1f, -0.1f});
	else if (key == A || key == Q || key == LEFT)
		player_move(mlx, 'L', (float [2]){0.1f, -0.1f});
		// press_move(all, &all->map, 'L');
	else if (key == S || key == DOWN)
		player_move(mlx, 'D', (float [2]){0.1f, -0.1f});
		// press_move(all, &all->map, 'D');
	else if (key == W || key == Z || key == UP)
		player_move(mlx, 'U', (float [2]){0.1f, -0.1f});
		// press_move(all, &all->map, 'U');
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	printf("player value\n\r X = %f\n\r Y = %f\n", mlx->player[X_POS], mlx->player[Y_POS]);
	print_min_map(mlx);
	return (0);
}

static int	ft_close(t_mlx *mlx)
{
	// mlx_do_key_autorepeaton(all->mlx.mlx);
	free_mlx(mlx);
	exit(0);
	return (0);
}

/**
	@brief	Function start to create the mlx for the graphics

	@param	t_tmp	Take in param all the info from the parsing

	@return	Return void
 **/
void	start_mlx(t_tmp *file)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.file = file;
	find_player_pos(file, &mlx);
	create_texture(&mlx);

	// print_rayon();

	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.pict[WALL].img, 0, 0);

	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_hook, &mlx);

	// mlx_hook(mlx.mlx_win, 15, 1L << 16, reset_window, all);

	mlx_hook(mlx.win_ptr, 33, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
