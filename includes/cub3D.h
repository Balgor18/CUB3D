/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 09:39:18 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "mlx.h"
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
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# define K "🔮🧡🍁🐞🍄🍀🌸🐹🌳🦊🐼🌿🧡🦊🧡🌿🐼🦊🌳🐹🌸🍀🍄🐞🍁🧡🔮\n"
# define Y "⛩ 🌸🦊    Launch ./so_long map_filename.ber     🦊🌸⛩\n"
# define A "⛩ 🌸🦊                                          🦊🌸⛩\n"
# define MARG "⛩ 🌸🦊             Missing Map file             🦊🌸⛩\n"
# define TMARG "⛩ 🌸🦊           Too Many Arguments             🦊🌸⛩\n"
# define WEXT "⛩ 🌸🦊           Wrong Map Extension            🦊🌸⛩\n"
# define OPENERR "⛩ 🌸🦊           Can't Open Map File            🦊🌸⛩\n"
# define OPENDIRERR "⛩ 🌸🦊      Map is  Directory not a File        🦊🌸⛩\n"
# define CLOSEERR "⛩ 🌸🦊           Can't Close Map File            🦊🌸⛩\n"
# define EMPTYMAP "⛩ 🌸🦊               Map is empty               🦊🌸⛩\n"
# define NRECTMAP "⛩ 🌸🦊          Map is not a rectangle          🦊🌸⛩\n"
# define WCHARMAP "⛩ 🌸🦊   Map is not only 0, 1, P, C, E chars    🦊🌸⛩\n"
# define NCLOSEDMAP "⛩ 🌸🦊        Map is not closed by 1 chars      🦊🌸⛩\n"
# define ZEROPMAP "⛩ 🌸🦊             Map has no player            🦊🌸⛩\n"
# define MULTIPMAP "⛩ 🌸🦊        Map has more than one player       🦊🌸⛩\n"
# define ZEROCMAP "⛩ 🌸🦊          Map has no collectible          🦊🌸⛩\n"
# define ZEROEMAP "⛩ 🌸🦊              Map has no exit             🦊🌸⛩\n"
# define GNLFAIL "⛩ 🌸🦊           Gnl Malloc fail error          🦊🌸⛩\n"
# define DATAFAIL "⛩ 🌸🦊          Data Malloc fail error          🦊🌸⛩\n"
# define ARRAYFAIL "⛩ 🌸🦊          Array Malloc fail error         🦊🌸⛩\n"
# define GAMEFAIL "⛩ 🌸🦊           Game Malloc fail error         🦊🌸⛩\n"
# define SCREENFAIL "⛩ 🌸🦊           Sceen Malloc fail error        🦊🌸⛩\n"
# define IMGFAIL "⛩ 🌸🦊           Image Malloc fail error        🦊🌸⛩\n"
# define TEXFAIL "⛩ 🌸🦊          Texture Malloc fail error        🦊🌸⛩\n"
# define IMGTEXFAIL "⛩ 🌸🦊       Texture Image Malloc fail error     🦊🌸⛩\n"
# define MLXINITFAIL "⛩ 🌸🦊     Mlx init fail (nice try env -i)      🦊🌸⛩\n"
# define MLXWINFAIL "⛩ 🌸🦊          Mlx new window failed           🦊🌸⛩\n"
# define MLXIMGFAIL "⛩ 🌸🦊           Mlx new image failed           🦊🌸⛩\n"
# define MLXADDRFAIL "⛩ 🌸🦊         Mlx data address failed          🦊🌸⛩\n"
# define GAME "⛩ 🌸🦊                Game Infos                🦊🌸⛩\n"
# define MAP "⛩ 🌸🦊                  Map                     🦊🌸⛩\n"
# define SCREEN "Max res = 2560 * 1440\n"
# define SCREENY "Map y = 22 tiles * 64 pixels = 1408"
# define SCREENX "Map x = 40 tiles * 64 pixels = 2560"
# define MAPTOOWIDE "⛩ 🌸🦊      Map's width is too big (40 max)     🦊🌸⛩\n"
# define MAPTOOHIGH "⛩ 🌸🦊      Map's height is too big (22 max)    🦊🌸⛩\n"

# define MAPCHAR "01NSWE"

/*
**---------------Enum---------------
*/

/*
**--------------struct--------------
*/
typedef struct s_tmp	t_tmp;
typedef struct s_mlx	t_mlx;

struct s_tmp
{
	char	*line;
	t_tmp	*next;
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
void	start_mlx(t_tmp *file);
#endif
