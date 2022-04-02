/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/02 17:21:37 by fcatinau         ###   ########.fr       */
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
	int	pos[2];
	char	*s;
	char **tmpb;

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
				mlx->player[X_POS] = pos[0];
				mlx->player[Y_POS] = pos[1];
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

// 0x00FFFF00
// 0x00FF00FF

// 0x00FF0000 --> Nothing
// 0x00FFFFFF --> Blue Again
// 0x000000FF --> Blue
// 0x00000F00 --> Nothing

// 0xTTRRGGBB
// 0x00F280FF --> BLUE
// 0x0000FF00 --> Nothing
// 0x000000FF --> BLUE
// 0x0000FF --> BLUE
// 0x00FF00 --> Nothing
// 0xFF0000 --> Nothing
// 0x00FF4D00

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

void	mlx_print_line(t_xptr const *const xptr, int const a[2], int const b[2],
	uint32_t const color)
{
	int dist[2], \
ori[2], c[2], err[2];
	__init0(dist, ori, a, b);
	__init1(err, dist, c, a);
	while (42)
	{
		mlx_pixel_put(xptr->mlx, xptr->win, c[X], c[Y], color);
		if (c[X] == b[X] && c[Y] == b[Y])
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= dist[Y])
		{
			if (c[X] == b[X])
				break ;
			err[0] = err[0] + dist[Y];
			c[X] = c[X] + ori[X];
		}
		if (err[1] <= dist[X])
		{
			if (c[Y] == b[Y])
				break ;
			err[0] = err[0] + dist[X];
			c[Y] = c[Y] + ori[Y];
		}
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
	// xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[CEILING], 0x00000000);
}

static double dist(double ax, double ay, double bx, double by)
{
	return (sqrt(bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

//	i[0] == Y
//	i[1] == X
static void	print_min_map(t_mlx *mlx)
{
	char **tmpb;
	char	*s;
	int		in[2];

	in[0] = 0;
	tmpb = mlx->map;
	while (*tmpb)
	{
		s = *tmpb;
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
		tmpb++;
	}

	//player
	int	i[2];

	i[0] = (mlx->player[X_POS] * 64) + 32;
	i[1] = (mlx->player[Y_POS] * 64) + 32;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[PLAYER].img, i[0], i[1]);

	// int	j;

	// j = 0;
	// double end_point[2];
	// //draw direction
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

	int	r,mx,my,dof; float rx, ry, ra, xo,yo;
	r = 0;
	ra = mlx->player[ANGLE];
	mlx->player[Y_POS] *= 64;
	mlx->player[X_POS] *= 64;
	while (r < 1)
	{
		// check horizontal
		dof = 0;
		float distH = 1000000,hx = mlx->player[X_POS],hy = mlx->player[Y_POS];
		float aTan = -1 / tan(ra);
		if (ra < M_PI)
		{
			ry = (((int)mlx->player[Y_POS] >> 6) << 6) - 0.0001;
			rx = (mlx->player[Y_POS] - ry) * aTan + mlx->player[X_POS];
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra > M_PI)
		{
			ry = (((int)mlx->player[Y_POS] >> 6) << 6) + 64;
			rx = (mlx->player[Y_POS] - ry) * aTan + mlx->player[X_POS];
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == M_PI)
		{
			rx = mlx->player[X_POS];
			ry = mlx->player[Y_POS];
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			printf("---------------------\nmx : %d\nmy : %d\n", mx, my);
			printf("rx : %f\nry : %f\n", rx, ry);
			if (0 < rx && rx < 16 * 64 && 0 < ry && ry < 6 * 64 && mlx->map[(int)ry / 64][(int)rx / 64] == '1')
			{
				hx = rx;
				hy = ry;
				dof = 8;
				distH = dist(mlx->player[X_POS], mlx->player[Y_POS], hx, hy);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, rx, ry, 0x00FF0000);

		// check vertical
		// dof = 0;
		// float distV = 1000000,vx = mlx->player[X_POS],vy = mlx->player[Y_POS];
		// float nTan = -tan(ra);
		// if (M_PI / 2 < ra && ra < 3 * M_PI / 2 )// left
		// {
		// 	printf("y player = %f\n", mlx->player[Y_POS]);
		// 	rx = (((int)mlx->player[X_POS] >> 6) << 6) - 0.0001;
		// 	ry = (mlx->player[X_POS] - rx) * nTan + mlx->player[Y_POS];
		// 	xo = -64;
		// 	yo = -xo * nTan;
		// }
		// if (ra < (M_PI / 2) || (3 * M_PI / 2) < ra)// right
		// {
		// 	rx = (((int)mlx->player[X_POS] >> 6) << 6) + 64;
		// 	ry = (mlx->player[X_POS] - rx) * nTan + mlx->player[Y_POS];
		// 	xo = 64;
		// 	yo = -xo * nTan;
		// }
		// if (ra == 0 || ra == M_PI)// up or own
		// {
		// 	rx = mlx->player[X_POS];
		// 	ry = mlx->player[Y_POS];
		// 	dof = 8;
		// } 
		// while (dof < 8)
		// {
		// 	mx = (int) (rx) >> 6;
		// 	my = (int) (ry) >> 6;
		// 	// printf("---------------------\nmx : %d\nmy : %d\n", mx, my);
		// 	// printf("rx : %f\nry : %f\n", rx, ry);
		// 	if (mlx->map[my][mx] == '1')
		// 	{
		// 		vx = rx;
		// 		vy = ry;
		// 		dof = 8;
		// 		distV = dist(mlx->player[X_POS], mlx->player[Y_POS],vx, vy);
		// 	}
		// 	else
		// 	{
		// 		rx += xo;
		// 		ry += yo;
		// 		dof += 1;
		// 	}
		// }
		// if (distV < distH)
		// {
		// 	rx = vx;
		// 	ry = vy;
		// }
		// if (distH < distV)
		// {
		// 	rx = hx;
		// 	ry = hy;
		// }
		// printf("Je print %f / %f\n", rx, ry);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, rx, ry, 0x00FF0000);
		r++;
	}
	// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, rx, ry, 0x00FF0000);
	mlx->player[Y_POS] /= 64;
	mlx->player[X_POS] /= 64;
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
		player_move(mlx, 'R', (double [2]){2 * M_PI/ 180, -(2 * M_PI/ 180)});
	else if (key == A || key == Q || key == LEFT)
		player_move(mlx, 'L', (double [2]){2 * M_PI/ 180, -(2 * M_PI/ 180)});
	else if (key == S || key == DOWN)
		player_move(mlx, 'D', (double [2]){2 * M_PI/ 180, -(2 * M_PI/ 180)});
	else if (key == W || key == Z || key == UP)
		player_move(mlx, 'U', (double [2]){2 * M_PI/ 180, -(2 * M_PI/ 180)});
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	print_min_map(mlx);
	return (0);
}

static int	ft_close(t_mlx *mlx)
{
	// mlx_do_key_autorepeaton(all->mlx.mlx);
	// ft_trash(all);
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
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.pict[WALL].img, 0, 0);

	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_hook, &mlx);

	// mlx_hook(mlx.mlx_win, 15, 1L << 16, reset_window, all);

	mlx_hook(mlx.win_ptr, 33, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
