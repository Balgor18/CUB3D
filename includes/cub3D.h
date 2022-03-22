/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/22 09:04:23 by grannou          ###   ########.fr       */
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
typedef struct s_data	t_infos;
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

// basic_parsing.c
void	parsing(int argc, char **argv);

// string_utils.c
int		ft_strlen(char *str);

// lst_utils.c
int		ft_lst_size(t_map *map);
t_map	*ft_lst_create(char *line);
void	ft_lst_clear(t_map **map);
t_map	*ft_lstlast(t_map *map);
t_map	*ft_lst_addback(t_map **map, t_map *elem);
void	print_list(t_map *map);

// free.c
void	clear_map_exit(t_map **map, char *sg);
void	clear_map_free_line_exit(t_map **map, char *line);

// main.c
void	exit_error(char *msg);
void	check_open(char *filename, int *fd);
void	clear_map_exit(t_map **map, char *msg);
int		check_close(int fd, t_map *map);

#endif
