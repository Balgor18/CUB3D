/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 10:33:49 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "mlx.h"
# include "erro.h"
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
	GROUNDTEX = 0,
	SKYTEX,
	NORTHTEX,
	SOUTHTEX,
	WESTTEXT,
	EASTTEX
};

/*
**--------------struct--------------
*/
typedef struct s_map	t_map;
typedef struct s_mlx	t_mlx;

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

// lst_utils.c
t_map	*ft_lst_create(char *line);
void	ft_lst_clear(t_map **map);
t_map	*ft_lstlast(t_map *map);
t_map	*ft_lst_addback(t_map **map, t_map *elem);

#endif
