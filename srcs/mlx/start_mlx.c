/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/31 19:35:17 by fcatinau         ###   ########.fr       */
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
			*angle = 0;
		else if (c == 'W')
			*angle = M_PI;
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

	str = ((pos[1] = 0, tmp));
	while (tmp)
	{
		pos[0] = ((s = *tmp, 0));
		while (*s)
		{
			if (is_player(*s, &mlx->player[ANGLE]))
			{
				mlx->player[X_POS] = ((*s = '0', pos[0]));
				mlx->player[Y_POS] = pos[1];
				mlx->delta[0] = cos(mlx->player[ANGLE]) * 5;
				mlx->delta[1] = sin(mlx->player[ANGLE]) * 5;
				return ;
			}
			pos[0] += ((s++, 1));
		}
		pos[1] += ((tmp++, 1));
	}
	tmp = str;
}

/**
 *
 *
**/
// static void	mlx_print_line(t_mlx *mlx, float start[2], float stop[2], int color)//, float delta)
// {
// 	double add[2];

// 	add[0] = (stop[0] - start[0]);
// 	add[1] = (stop[1] - start[1]);

// 	while (start[0] < stop[0] || start[1] < stop[1])
// 	{
// 		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, start[0], start[1], color);
// 		start[0] += add[0] / add[1];
// 		start[1]++;
// 	}
// }

// void mlx_print_line(t_mlx *mlx, float start[2], float stop[2], int color)
// {
// 	int dx, dy, p, x, y;

// 	dx = stop[0] - start[0];
// 	dy = stop[1] - start[1];
// 	x = start[0];
// 	y = start[1];
// 	p = 2 * dy - dx;
// 	while(x < stop[0])
// 	{
// 		if(p >= 0)
// 		{
// 			// putpixel(x, y,7);
// 			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
// 			y = y + 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			// putpixel(x, y, 7);
// 			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
// 			p = p + 2 * dy;
// 		}
// 		x = x + 1;
// 	}
// }

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

	i[0] = (mlx->player[X_POS] * 64) + 32;
	i[1] = (mlx->player[Y_POS] * 64) + 32;
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[PLAYER].img, i[0], i[1]);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i[0], i[1], 0x0000FF00);
	// Juste a direction line

	// float	end_point[2];
	// i[0] += 8;
	// i[1] += 8;

	// int		j;
	// j = 0;
	// // printf("Player :\n\rX = %f\n\rY = %f\n", i[0], i[1]);
	// // printf("Delta : \n\rX = %f\n\rY = %f\n", mlx->delta[0], mlx->delta[1]);
	// while (j < 400)
	// {
	// 	end_point[0] = 0.1 * mlx->delta[0];
	// 	end_point[1] = 0.1 * mlx->delta[1];
	// 	// ----- X -----
	// 	if (mlx->delta[0] > 0)
	// 		end_point[0] *= -j;
	// 	else
	// 		end_point[0] *= -j;

	// 	// ----- Y -----
	// 	if (mlx->delta[1] > 0)
	// 		end_point[1] *= -j;
	// 	else
	// 		end_point[1] *= -j;

	// 	end_point[0] += i[0];
	// 	end_point[1] += i[1];
	// 	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, end_point[0], end_point[1], 0x00FFFF00);
	// 	j++;
	// }


	// mlx_print_line(mlx, (float [2]){0, 0}, (float [2]){3 * 64, 2 * 64}, 0x00FF0000);


	// float	end_point[2];

	int		mapX;
	int		mapY;

	mapX = 16;
	mapY = 6;

	int	int_array[MAX_RAY];
	double	f[MAX_FLOAT];

	int_array[RAYON] = 0;
	mlx->player[X_POS] *= 64;
	mlx->player[Y_POS] *= 64;

	// mlx->player[X_POS] -= 32;
	// mlx->player[Y_POS] -= 32;

	while (int_array[RAYON] < 1)
	{
		//check horizontal
		int_array[DOF] = 0;

		double aTan = -1/tan(mlx->player[ANGLE]);

		if (mlx->player[ANGLE] < M_PI)//looking up
		{
			printf(RED"Je regarde vers le haut\n"RESET);
			f[RY] = (((int)mlx->player[Y_POS] >> 6) << 6) - 0.0001;
			f[RX] = (mlx->player[Y_POS] - f[RY]) * aTan + mlx->player[X_POS];
			f[YO] = -64;
			f[XO] = -f[YO] * aTan;
		}
		if (mlx->player[ANGLE] > M_PI)//looking down
		{
			printf(GREEN"Je regarde vers le bas\n"RESET);
			f[RY] = (((int)mlx->player[Y_POS] >> 6) << 6) + 64;
			f[RX] = (mlx->player[Y_POS] - f[RY]) * aTan + mlx->player[X_POS];
			f[YO] = 64;
			f[XO] = -f[YO] * aTan;
		}
		if (mlx->player[ANGLE] == 0 || mlx->player[ANGLE] == M_PI)// left and right // Right and left dosent work
		{
			printf(CYAN"Je regarde vers la droite ou la gauche\n"RESET);
			f[RX] = mlx->player[X_POS];
			f[RY] = mlx->player[Y_POS];
			int_array[DOF] = 8;
		}
		while (int_array[DOF] < 8)
		{
			// printf("RX = %f\nRY = %f\n", f[RX], f[RY]);
			// f[RX] += 32/64;
			// f[RY] += 32/64;
			int_array[MX] = (int)(f[RX])>>6;
			int_array[MY] = (int)(f[RY])>>6;
			// printf("------\nY = %d\nX = %d\n", int_array[MX], int_array[MY]);
			// printf("f[RX] = %f\nf[RY] = %f\n", f[RX] / 64, f[RY] / 64);
			// f[RX] += 0.5;
			// f[RY] += 0.5;
			// printf("f[RX] = %f\nf[RY] = %f\n", f[RX] / 64, f[RY] / 64);
			if (int_array[MX] > 0 && int_array[MX] < 16 && int_array[MY] < 6 && mlx->map[int_array[MY]][int_array[MX]] == '1')// wall hit
			{
				int_array[DOF] = 8;
			}
			else
			{
				f[RX] += f[XO];
				f[RY] += f[YO];
				int_array[DOF] += 1;
			}
		}
		//print HERE
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, f[RX], f[RY], 0x00FF0000);

		// ----- vertical ------
		int_array[DOF] = 0;
		aTan = -1/tan(mlx->player[ANGLE]);
		if (mlx->player[ANGLE] > M_PI / 2 && mlx->player[ANGLE] < 3 * M_PI / 2)//looking left
		{
			printf(RED"Je regarde vers le haut\n"RESET);
			f[RX] = (((int)mlx->player[X_POS] >> 6) << 6) - 0.0001;
			f[RY] = (mlx->player[X_POS] - f[RX]) * aTan + mlx->player[Y_POS];
			f[XO] = -64;
			f[YO] = -f[XO] * aTan;
		}
		if (mlx->player[ANGLE] < M_PI / 2 || mlx->player[ANGLE] > 3 * M_PI / 2)//looking right
		{
			printf(GREEN"Je regarde vers le bas\n"RESET);
			f[RX] = (((int)mlx->player[X_POS] >> 6) << 6) + 64;
			f[RY] = (mlx->player[X_POS] - f[RX]) * aTan + mlx->player[Y_POS];
			f[XO] = 64;
			f[YO] = -f[XO] * aTan;
		}
		if (mlx->player[ANGLE] == 0 || mlx->player[ANGLE] == M_PI)// up or down
		{
			printf(CYAN"Je regarde vers la droite ou la gauche\n"RESET);
			f[RX] = mlx->player[X_POS];
			f[RY] = mlx->player[Y_POS];
			int_array[DOF] = 8;
		}
		while (int_array[DOF] < 8)
		{
			int_array[MX] = (int)(f[RX])>>6;
			int_array[MY] = (int)(f[RY])>>6;
			if (int_array[MX] > 0 && int_array[MX] < 16 && int_array[MY] < 6 && mlx->map[int_array[MY]][int_array[MX]] == '1')// wall hit
			{
				int_array[DOF] = 8;
			}
			else
			{
				f[RX] += f[XO];
				f[RY] += f[YO];
				int_array[DOF] += 1;
			}
		}
		int_array[RAYON]++;
	}



	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, f[RX], f[RY], 0x00FF0000);
	// mlx->player[X_POS] /=64;
	// mlx->player[Y_POS] /=64;
	// printf("player : \n\tX = %f\n\tY = %f\n", mlx->player[X_POS], mlx->player[Y_POS]);
	// printf("end :\n\tX = %f\n\tY = %f\n", f[RX], f[RY]);

	int_array[MX] *= 64;
	// int_array[MX] -= 32;

	int_array[MY] *= 64;
	// int_array[MY] += 64;
	// printf("player : \n\tX = %f\n\tY = %f\n", mlx->player[X_POS] - 32, mlx->player[Y_POS]);
	// printf("end :\n\tX = %d\n\tY = %d\n", int_array[MX], int_array[MY]);
	// mlx_print_line(mlx, (float [2]){int_array[MX] - 32, f[RY]}, (float [2]){mlx->player[X_POS] - 32, mlx->player[Y_POS] - 32}, 0x00FF0000);

	// mlx->player[X_POS] += 32;
	// mlx->player[Y_POS] += 32;
	mlx->player[X_POS] /=64;
	mlx->player[Y_POS] /=64;

	// mlx->player[X_POS] *= 64;
	// mlx->player[Y_POS] *= 64;
	//useless
	// mlx_print_line(mlx, (float [2]){0, 0}, (float [2]){0, 0}, 0);

	// int	start[2] = {mlx->player[X_POS], mlx->player[Y_POS]};

	// while (start[0] < f[RX] && start[1] < f[RY])
	// {
	// 	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, start[0] * 64, start[1] * 64, 0x00FFFF00);
	// 	start[0]++;
	// 	start[1]++;
	// }
	// printf("int_array : \n\rRayon = %d\n\rMX = %d\n\rMY = %d\n\rMP = %d\n\rDOF = %d\n", int_array[RAYON], int_array[MX], int_array[MY], int_array[MP], int_array[DOF]);
	// printf("float : \n\rRX = %f\n\rRY = %f\n\rRA = %f\n\rXO = %f\n\rYO = %f\n", f[RX], f[RY], f[RA], f[XO], f[YO]);
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
	// printf("angle = %f\n", mlx->player[ANGLE]);
	// printf("PI / 2 = %f\n", M_PI / 2);
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
 *
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
	player[0][0] = 0.1f * mlx->delta[0];
	player[0][1] = 0.1f * mlx->delta[1];
	player[1][0] = -0.1f * mlx->delta[0];
	player[1][1] = -0.1f * mlx->delta[1];
	if (move == 'U' || move == 'D')
	{
		mlx->player[Y_POS] += *(double *)ft_ternary(move == 'U', &player[1][1],
				&player[0][1]);
		mlx->player[X_POS] += *(double *)ft_ternary(move == 'U', &player[1][0],
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
		player_move(mlx, 'R', (double [2]){2 * M_PI/ 180, -2 * M_PI/ 180});
	else if (key == A || key == Q || key == LEFT)
		player_move(mlx, 'L', (double [2]){2 * M_PI/ 180, -2 * M_PI/ 180});
	else if (key == S || key == DOWN)
		player_move(mlx, 'D', (double [2]){2 * M_PI/ 180, -2 * M_PI/ 180});
	else if (key == W || key == Z || key == UP)
		player_move(mlx, 'U', (double [2]){2 * M_PI/ 180, -2 * M_PI/ 180});
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

	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.pict[WALL].img, 0, 0);

	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_hook, &mlx);

	// mlx_hook(mlx.mlx_win, 15, 1L << 16, reset_window, all);

	mlx_hook(mlx.win_ptr, 33, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
