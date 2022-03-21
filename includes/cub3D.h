/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 11:17:31 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "mlx.h"
# include "error.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
/*
 FONCTIONS AUTORISEES:
open, cose, read, write, printf, malloc, free, perror, strerror, exit
toutes les fonctions de math.h
*/

/*
**---------------Enum---------------
*/

enum	e_MOVE
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

enum	e_TEXTURE
{
	FLOORTEX = 0,
	CEILINGTEX,
	NORTHTEX,
	SOUTHTEX,
	WESTTEXT,
	EASTTEX
};

enum	e_RGB
{
	RED_COLOR = 0,
	GREEN_COOR,
	BLUE_COLOR
};

/*
**--------------struct--------------
*/
typedef struct s_data	t_data;
typedef struct s_rgb	t_rgb;
typedef struct s_map	t_map;
typedef struct s_mlx	t_mlx;

struct s_infos
{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_rgb	*floor;
	t_rgb	*ceiling;
	int		map_height;
	int		map_width;
	int		map_chars;
};

struct s_rgb
{
	int		red;
	int		green;
	int		blue;
};

struct s_map
{
	char	*mapline;
	int		line_size;
	t_map	*next;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
};

/*
**----------------------------------
**----------------MLX---------------
**----------------------------------
*/
void	start_mlx(t_map *file);

// string_utils.c
int		ft_strlen(char *str);

// lst_utils.c
t_map	*ft_lst_create(char *line);
void	ft_lst_clear(t_map **map);
t_map	*ft_lstlast(t_map *map);
t_map	*ft_lst_addback(t_map **map, t_map *elem);

#endif
