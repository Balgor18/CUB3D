/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/05 05:01:02 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include <stdio.h>
# include "mlx.h"
# include <stdbool.h>
# include "key_linux.h"

/*
**---------------Enum---------------
*/

enum	e_player
{
	X_POS,
	Y_POS,
	X_PIXEL,
	Y_PIXEL,
	ANGLE,
	MAX_POS,
};

enum	e_img
{
	PLAYER,
	WALL,
	FLOOR,
	CEILING,
	MAX_IMG,
};

/*
**--------------struct--------------
*/
typedef struct s_tmp	t_tmp;
typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;

struct s_tmp
{
	char	*line;
	t_tmp	*next;
};

struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	pict[MAX_IMG];
	double	player[MAX_POS];
	double	delta[2];
	char	**map;
};

/*
**----------------------------------
**----------------MLX---------------
**----------------------------------
*/

void	start_mlx(char **map);
void	create_texture(t_mlx *mlx);
void	free_mlx(t_mlx *mlx);
void	print_3d(t_mlx *mlx, int rayon, double ra, int *x);
void	mlx_print_line(t_mlx *mlx, int const a[2], int const b[2],
			int const color);
double	dist(double ax, double ay, double bx, double by);
double	vertical_check(t_mlx *mlx, double ra);
double	horizontal_check(t_mlx *mlx, double ra);
void	find_player_pos(char **tmp, t_mlx *mlx);
void	*ft_ternary(int const cond, void *valid_1, void *valid_2);
size_t	ft_strlen(char *s);

#endif
