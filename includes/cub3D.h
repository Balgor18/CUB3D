/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/29 15:21:54 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <stdio.h>
# include "mlx.h"
# include <stdbool.h>
# include "key_linux.h"

# define BLACK "\033[0;30m"
# define BLUE "\033[0;34m"
# define CYAN "\033[0;36m"
# define GREEN "\033[0;32m"
# define PURPLE "\033[0;35m"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
# define YELLOW "\033[0;33m"
# define RESET "\e[0m"

# ifndef M_PI
#  define M_PI 3.1415926535
# endif

/*
**---------------Enum---------------
*/

enum	e_player
{
	X_POS,
	Y_POS,
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
** Tmp
*/
enum e_ray3D
{
	RAYON,
	MX,
	MY,
	MP,
	DOF,
	MAX_RAY,
};

enum e_floatray_3D
{
	RX,
	RY,
	RA,
	XO,
	YO,
	MAX_FLOAT,
};

/*
**--------------struct--------------
*/
typedef struct	s_tmp t_tmp;
typedef struct	s_img t_img;
typedef struct	s_mlx t_mlx;

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
	double	delta[2];// 0 = X | 1 = Y check if needed
	char	**map;
};

/*
**----------------------------------
**----------------MLX---------------
**----------------------------------
*/

void	start_mlx(char **file);
void	free_mlx(t_mlx *mlx);
#endif
