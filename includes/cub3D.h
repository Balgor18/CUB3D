/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/22 23:18:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
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
	float	player[MAX_POS];
	t_tmp	*file;
};

/*
**----------------------------------
**----------------MLX---------------
**----------------------------------
*/

void	start_mlx(t_tmp *file);
void	free_mlx(t_mlx *mlx);
#endif
