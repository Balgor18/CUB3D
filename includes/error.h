/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:12:09 by grannou           #+#    #+#             */
/*   Updated: 2022/04/08 18:38:59 by grannou          ###   ########.fr       */
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

# define KYU "🔮🧡🍁🐞🍄🍀🌸🐹🌳🦊🐼🌿🧡🦊🧡🌿🐼🦊🌳🐹🌸🍀🍄🐞🍁🧡🔮\n"
# define LAUNCH "🍀🌸🦊    Launch ./cub3D map_filename.cub     🦊🌸🍀\n"
# define BIE "🍀🌸🦊                                          🦊🌸🍀\n"
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
# define SUBTRIMFAIL "🍀🌸🦊           Sub trim Malloc fail           🦊🌸🍀\n"
# define COMASFAIL "🍀🌸🦊     Split RGB on comas Malloc fail       🦊🌸🍀\n"
# define MISSRGB "🍀🌸🦊     Missing RGB value, three needed      🦊🌸🍀\n"
# define TMRGB "🍀🌸🦊     Too much RGB values, three needed    🦊🌸🍀\n"
# define BIGRGB "🍀🌸🦊             RGB value too big            🦊🌸🍀\n"
# define SYNTAXRGB "🍀🌸🦊          RGB value syntax error          🦊🌸🍀\n"

# define OPENDIRNOTEX "🍀🌸🦊       North Texture is Directory         🦊🌸🍀\n"
# define OPENDIRSOTEX "🍀🌸🦊       South Texture is Directory         🦊🌸🍀\n"
# define OPENDIRWETEX "🍀🌸🦊       West Texture is Directory          🦊🌸🍀\n"
# define OPENDIREATEX "🍀🌸🦊       East Texture is Directory          🦊🌸🍀\n"
# define OPENNOTEX "🍀🌸🦊        Can't Open North Texture          🦊🌸🍀\n"
# define OPENSOTEX "🍀🌸🦊        Can't Open South Texture          🦊🌸🍀\n"
# define OPENWETEX "🍀🌸🦊        Can't Open West Texture           🦊🌸🍀\n"
# define OPENEATEX "🍀🌸🦊        Can't Open East Texture           🦊🌸🍀\n"

# define EMPTYNOTEX "🍀🌸🦊         North Texture is empty             🦊🌸🍀\n"
# define EMPTYSOTEX "🍀🌸🦊         South Texture is empty             🦊🌸🍀\n"
# define EMPTYWETEX "🍀🌸🦊         West Texture is empty              🦊🌸🍀\n"
# define EMPTYEATEX "🍀🌸🦊         East Texture is empty              🦊🌸🍀\n"
# define WNOEXT "🍀🌸🦊      Wrong North Texture Extension       🦊🌸🍀\n"
# define WSOEXT "🍀🌸🦊      Wrong South Texture Extension       🦊🌸🍀\n"
# define WWEEXT "🍀🌸🦊      Wrong West Texture Extension        🦊🌸🍀\n"
# define WEAEXT "🍀🌸🦊      Wrong East Texture Extension        🦊🌸🍀\n"
# define SIZENOTEX "🍀🌸🦊     North Texture sie is not 64 x 64     🦊🌸🍀\n"
# define SIZESOTEX "🍀🌸🦊     South Texture sie is not 64 x 64     🦊🌸🍀\n"
# define SIZEWETEX "🍀🌸🦊      West Texture sie is not 64 x 64     🦊🌸🍀\n"
# define SIZEEATEX "🍀🌸🦊      East Texture sie is not 64 x 64     🦊🌸🍀\n"
# define MLXFAIL "🍀🌸🦊      Mlx init fail (nice try env -i)     🦊🌸🍀\n"
# define MAPFAIL "🍀🌸🦊           Map Malloc fail error          🦊🌸🍀\n"
# define WCHARMAP "🍀🌸🦊     Map is not only ' 01NSWE' chars      🦊🌸🍀\n"
# define SPLITMAP "🍀🌸🦊      Map is splitted by space line       🦊🌸🍀\n"

# define NCLOSEDMAP "🍀🌸🦊        Map is not closed by 1 chars      🦊🌸🍀\n"
# define ZEROPMAP "🍀🌸🦊             Map has no player            🦊🌸🍀\n"
# define MULTIPMAP "🍀🌸🦊       Map has more than one player       🦊🌸🍀\n"
# define GNLFAIL "🍀🌸🦊           Gnl Malloc fail error          🦊🌸🍀\n"
# define SCREENFAIL "🍀🌸🦊           Screen Malloc fail error        🦊🌸🍀\n"
# define IMGFAIL "🍀🌸🦊           Image Malloc fail error        🦊🌸🍀\n"
# define TEXFAIL "🍀🌸🦊          Texture Malloc fail error        🦊🌸🍀\n"
# define IMGTEXFAIL "🍀🌸🦊       Texture Image Malloc fail error     🦊🌸🍀\n"
# define MLXINITFAIL "🍀🌸🦊     Mlx init fail (nice try env -i)      🦊🌸🍀\n"
# define MLXWINFAIL "🍀🌸🦊          Mlx new window failed           🦊🌸🍀\n"
# define MLXIMGFAIL "🍀🌸🦊           Mlx new image failed           🦊🌸🍀\n"
# define MLXADDRFAIL "🍀🌸🦊         Mlx data address failed          🦊🌸🍀\n"

# define MAPCHAR "01NSWE"

#endif
