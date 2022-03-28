/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/28 18:59:09 by fcatinau         ###   ########.fr       */
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
		return (true);
	}
	return (false);
}

// pos[0] = X;
// pos[1] = Y;
static void	find_player_pos(char **tmp, t_mlx *mlx)
{
	int		pos[2];
	char	**str;
	char	*s;

	str = ((pos[1] = 1, tmp));
	while (tmp)
	{
		pos[0] = ((s = *tmp, 1));
		while (*s)
		{
			if (is_player(*s, &mlx->player[ANGLE]))
			{
				mlx->player[X_POS] = ((*s = '0', pos[0]));
				mlx->player[Y_POS] = pos[1];
				mlx->delta[0] = cos(mlx->player[ANGLE]);
				mlx->delta[1] = sin(mlx->player[ANGLE]);
				return ;
			}
			pos[0] += ((s++, 1));
		}
		pos[1] += ((tmp++, 1));
	}
	tmp = str;
}

static void	xpm_file_and_addr(void *mlx_ptr, t_img *img, int byte)
{
	int	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, 64, 64);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->bits_per_pixel, &img->endian);
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
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->bits_per_pixel, &img->endian);
	while (i < 256)
	{
		img->addr[i] = byte;
		i++;
	}
}

//	in[0] == Y
//	in[1] == X
static void	print_min_map(t_mlx *mlx)
{
	char	**str;
	char	*s;
	int		in[2];

	in[0] = 0;
	str = mlx->map;
	while (*str)
	{
		s = *str;
		in[1] = 0;
		while (*s)
		{
			if (*s == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->pict[WALL].img, in[1], in[0]);
			// else if (*s == '0')
			// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			//		mlx->pict[FLOOR].img, in[1], in[0]);
			s++;
			in[1] += 64;
		}
		in[0] += 64;
		str++;
	}

	//player
	float	i[2];

	i[0] = (mlx->player[X_POS] * 64) - 40;
	i[1] = (mlx->player[Y_POS] * 64) - 40;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[PLAYER].img, i[0], i[1]);

	// Juste a direction line

	float	end_point[2];
	i[0] += 8;
	i[1] += 8;

	int		j;


	float	delta_bis[2] = {0};
	float	angle_bis;

	float		lenght_line[60] = {0};
	int			test = 0;

	angle_bis = mlx->player[ANGLE] - (30 * M_PI / 180);
	while (angle_bis < mlx->player[ANGLE] + (30 * M_PI / 180))// while for all the line
	{
		delta_bis[0] = cos(angle_bis);
		delta_bis[1] = sin(angle_bis);
		end_point[0] = mlx->player[X_POS] * 64;
		end_point[1] = mlx->player[Y_POS] * 64;
		j = 0;
		while (mlx->map[(int)(end_point[1] / 64)][(int)((end_point[0] / 64))] == '0')
		{
			end_point[0] = 0.1 * delta_bis[0];
			end_point[1] = 0.1 * delta_bis[1];
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
		// end_point[0] -= mlx->player[X_POS];
		// end_point[1] -= mlx->player[Y_POS];
		// int	calcul_len(int *start)
		float	bro[2];

		bro[0] = fabs((end_point[0] - mlx->player[X_POS] * 64) * 2);
		bro[1] = fabs((end_point[1] - mlx->player[Y_POS] * 64) * 2);
		printf("bro : \n\t0 = %f\n\t1 = %f\n", bro[0], bro[1]);
		lenght_line[test] = sqrtf( bro[0] + bro[1]);
		test++;
		angle_bis += (1 * M_PI / 180);
	}
	// printf(GREEN"Done \n"RESET);
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

/**
 * @brief Function for a ternaire
 *
 * @param cond for the conditions
 * @param valid_1 if cond is true return valid_1
 * @param valid_2 if cond is false return valid_2
 * @return void* the value of valid_1 or valid_2
 */
void	*ft_ternary(int const cond, void *valid_1, void *valid_2)
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
	float	player[2][2];

	if (move == 'R' || move == 'L')
	{
		mlx->player[ANGLE] += *(float *)ft_ternary(move == 'R', &t[0], &t[1]);
		if (mlx->player[ANGLE] < 0)
			mlx->player[ANGLE] += 2 * M_PI;
		else if (mlx->player[ANGLE] > 2 * M_PI)
			mlx->player[ANGLE] -= 2 * M_PI;
		mlx->delta[0] = cos(mlx->player[ANGLE]);
		mlx->delta[1] = sin(mlx->player[ANGLE]);
	}
	player[0][0] = 0.1f * mlx->delta[0];
	player[0][1] = 0.1f * mlx->delta[1];
	player[1][0] = -0.1f * mlx->delta[0];
	player[1][1] = -0.1f * mlx->delta[1];
	if (move == 'U' || move == 'D')
	{
		mlx->player[Y_POS] += *(float *)ft_ternary(move == 'U', &player[1][1],
				&player[0][1]);
		mlx->player[X_POS] += *(float *)ft_ternary(move == 'U', &player[1][0],
				&player[0][0]);
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
		player_move(mlx, 'R', (float [2]){(2 * M_PI / 180), -(2 * M_PI / 180)});
	else if (key == A || key == Q || key == LEFT)
		player_move(mlx, 'L', (float [2]){(2 * M_PI / 180), -(2 * M_PI / 180)});
	else if (key == S || key == DOWN)
		player_move(mlx, 'D', (float [2]){(2 * M_PI / 180), -(2 * M_PI / 180)});
	else if (key == W || key == Z || key == UP)
		player_move(mlx, 'U', (float [2]){(2 * M_PI / 180), -(2 * M_PI / 180)});
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
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
void	start_mlx(char **file)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.map = file;
	find_player_pos(mlx.map, &mlx);
	create_texture(&mlx);

	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_hook, &mlx);

	// mlx_hook(mlx.mlx_win, 15, 1L << 16, reset_window, all);

	mlx_hook(mlx.win_ptr, 33, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
