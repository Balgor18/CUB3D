/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:12:09 by grannou           #+#    #+#             */
/*   Updated: 2022/03/27 16:25:44 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3D.h"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# define K "🔮🧡🍁🐞🍄🍀🌸🐹🌳🦊🐼🌿🧡🦊🧡🌿🐼🦊🌳🐹🌸🍀🍄🐞🍁🧡🔮\n"
# define Y "🍀🌸🦊    Launch ./cub3D map_filename.cub     🦊🌸🍀\n"
# define A "🍀🌸🦊                                          🦊🌸🍀\n"
# define LIST "🍀🌸🦊          Linked list of map file         🦊🌸🍀\n"
# define GAME "🍀🌸🦊                Game Infos                🦊🌸🍀\n"
# define MAP "🍀🌸🦊                  Map                     🦊🌸🍀\n"

# define MARG "🍀🌸🦊             Missing Map file             🦊🌸🍀\n"
# define TMARG "🍀🌸🦊           Too Many Arguments             🦊🌸🍀\n"
# define WEXT "🍀🌸🦊           Wrong Map Extension            🦊🌸🍀\n"
# define OPENERR "🍀🌸🦊           Can't Open Map File            🦊🌸🍀\n"
# define OPENDIRERR "🍀🌸🦊      Map is  Directory not a File        🦊🌸🍀\n"
# define CLOSEERR "🍀🌸🦊           Can't Close Map File            🦊🌸🍀\n"
# define CLOSETEX "🍀🌸🦊         Can't Close Texture File          🦊🌸🍀\n"
# define EMPTYMAP "🍀🌸🦊               Map is empty               🦊🌸🍀\n"
# define SYNTAX "🍀🌸🦊       Wrong line syntax in mapfile       🦊🌸🍀\n"
# define DUPNO "🍀🌸🦊          Multiple North textures         🦊🌸🍀\n"
# define DUPSO "🍀🌸🦊          Multiple South textures         🦊🌸🍀\n"
# define DUPWE "🍀🌸🦊          Multiple West textures          🦊🌸🍀\n"
# define DUPEA "🍀🌸🦊          Multiple East textures          🦊🌸🍀\n"
# define DUPF "🍀🌸🦊       Multiple Floor colors line         🦊🌸🍀\n"
# define DUPC "🍀🌸🦊      Multiple Ceiling colors lines       🦊🌸🍀\n"
# define MISSNO "🍀🌸🦊        North texture line missing        🦊🌸🍀\n"
# define MISSSO "🍀🌸🦊        South texture line missing        🦊🌸🍀\n"
# define MISSWE "🍀🌸🦊        West texture line missing         🦊🌸🍀\n"
# define MISSEA "🍀🌸🦊        East texture line missing         🦊🌸🍀\n"
# define MISSF "🍀🌸🦊         FLoor color line missing         🦊🌸🍀\n"
# define MISSC "🍀🌸🦊        Ceiling color line missing        🦊🌸🍀\n"
# define ENDFILE "🍀🌸🦊       Map must be the last element       🦊🌸🍀\n"

# define DATAFAIL "🍀🌸🦊             Data Malloc fail             🦊🌸🍀\n"
# define NORTHFAIL "🍀🌸🦊     Data North Texture Malloc fail       🦊🌸🍀\n"
# define SOUTHFAIL "🍀🌸🦊     Data South Texture Malloc fail       🦊🌸🍀\n"
# define WESTFAIL "🍀🌸🦊      Data West Texture Malloc fail       🦊🌸🍀\n"
# define EASTFAIL "🍀🌸🦊      Data East Texture Malloc fail       🦊🌸🍀\n"
# define FLOORFAIL "🍀🌸🦊         Data Floor RGB Malloc fail       🦊🌸🍀\n"
# define CEILINGFAIL "🍀🌸🦊       Data Ceiling RGB Malloc fail       🦊🌸🍀\n"
# define COMASFAIL "🍀🌸🦊     Split RGB on comas Malloc fail       🦊🌸🍀\n"
# define MISSRGB "🍀🌸🦊     Missing RGV value, three needed      🦊🌸🍀\n"
# define TMRGB "🍀🌸🦊     Too much RGB values, three needed    🦊🌸🍀\n"

# define OPENDIRTEX "🍀🌸🦊    Texture is  Directory not a File      🦊🌸🍀\n"
# define OPENTEX "🍀🌸🦊         Can't Open Texture File          🦊🌸🍀\n"
# define EMPTYTEX "🍀🌸🦊             Texture is empty             🦊🌸🍀\n"

# define WCHARMAP "🍀🌸🦊  Map is not only 0, 1, N, S, W, E chars  🦊🌸🍀\n"
# define NCLOSEDMAP "🍀🌸🦊        Map is not closed by 1 chars      🦊🌸🍀\n"
# define ZEROPMAP "🍀🌸🦊             Map has no player            🦊🌸🍀\n"
# define MULTIPMAP "🍀🌸🦊        Map has more than one player       🦊🌸🍀\n"
# define GNLFAIL "🍀🌸🦊           Gnl Malloc fail error          🦊🌸🍀\n"
# define ARRAYFAIL "🍀🌸🦊          Array Malloc fail error         🦊🌸🍀\n"
# define SCREENFAIL "🍀🌸🦊           Screen Malloc fail error        🦊🌸🍀\n"
# define IMGFAIL "🍀🌸🦊           Image Malloc fail error        🦊🌸🍀\n"
# define TEXFAIL "🍀🌸🦊          Texture Malloc fail error        🦊🌸🍀\n"
# define IMGTEXFAIL "🍀🌸🦊       Texture Image Malloc fail error     🦊🌸🍀\n"
# define MLXINITFAIL "🍀🌸🦊     Mlx init fail (nice try env -i)      🦊🌸🍀\n"
# define MLXWINFAIL "🍀🌸🦊          Mlx new window failed           🦊🌸🍀\n"
# define MLXIMGFAIL "🍀🌸🦊           Mlx new image failed           🦊🌸🍀\n"
# define MLXADDRFAIL "🍀🌸🦊         Mlx data address failed          🦊🌸🍀\n"
# define SCREEN "Max res = 2560 * 1440\n"
# define SCREENY "Map y = 22 tiles * 64 pixels = 1408"
# define SCREENX "Map x = 40 tiles * 64 pixels = 2560"
# define MAPTOOWIDE "🍀🌸🦊     Map's width is too big (1440 max)    🦊🌸🍀\n"
# define MAPTOOHIGH "🍀🌸🦊     Map's height is too big (2560 max)   🦊🌸🍀\n"
# define MAPTOOBIG "🍀🌸🦊        Map's res max = 2560 * 1440       🦊🌸🍀\n"

# define MAPCHAR "01NSWE"

#endif