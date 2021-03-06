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

# define KYU "๐ฎ๐งก๐๐๐๐๐ธ๐น๐ณ๐ฆ๐ผ๐ฟ๐งก๐ฆ๐งก๐ฟ๐ผ๐ฆ๐ณ๐น๐ธ๐๐๐๐๐งก๐ฎ\n"
# define LAUNCH "๐๐ธ๐ฆ    Launch ./cub3D map_filename.cub     ๐ฆ๐ธ๐\n"
# define BIE "๐๐ธ๐ฆ                                          ๐ฆ๐ธ๐\n"
# define LIST "๐๐ธ๐ฆ          Linked list of map file         ๐ฆ๐ธ๐\n"
# define GAME "๐๐ธ๐ฆ                Game Infos                ๐ฆ๐ธ๐\n"
# define MAP "๐๐ธ๐ฆ                  Map                     ๐ฆ๐ธ๐\n"

# define MARG "๐๐ธ๐ฆ             Missing Map file             ๐ฆ๐ธ๐\n"
# define TMARG "๐๐ธ๐ฆ           Too Many Arguments             ๐ฆ๐ธ๐\n"
# define WEXT "๐๐ธ๐ฆ           Wrong Map Extension            ๐ฆ๐ธ๐\n"
# define OPENERR "๐๐ธ๐ฆ           Can't Open Map File            ๐ฆ๐ธ๐\n"
# define OPENDIRERR "๐๐ธ๐ฆ      Map is  Directory not a File        ๐ฆ๐ธ๐\n"
# define CLOSEERR "๐๐ธ๐ฆ           Can't Close Map File            ๐ฆ๐ธ๐\n"
# define CLOSETEX "๐๐ธ๐ฆ         Can't Close Texture File          ๐ฆ๐ธ๐\n"
# define EMPTYMAP "๐๐ธ๐ฆ               Map is empty               ๐ฆ๐ธ๐\n"
# define SYNTAX "๐๐ธ๐ฆ       Wrong line syntax in mapfile       ๐ฆ๐ธ๐\n"
# define DUPNO "๐๐ธ๐ฆ          Multiple North textures         ๐ฆ๐ธ๐\n"
# define DUPSO "๐๐ธ๐ฆ          Multiple South textures         ๐ฆ๐ธ๐\n"
# define DUPWE "๐๐ธ๐ฆ          Multiple West textures          ๐ฆ๐ธ๐\n"
# define DUPEA "๐๐ธ๐ฆ          Multiple East textures          ๐ฆ๐ธ๐\n"
# define DUPF "๐๐ธ๐ฆ       Multiple Floor colors line         ๐ฆ๐ธ๐\n"
# define DUPC "๐๐ธ๐ฆ      Multiple Ceiling colors lines       ๐ฆ๐ธ๐\n"
# define MISSNO "๐๐ธ๐ฆ        North texture line missing        ๐ฆ๐ธ๐\n"
# define MISSSO "๐๐ธ๐ฆ        South texture line missing        ๐ฆ๐ธ๐\n"
# define MISSWE "๐๐ธ๐ฆ        West texture line missing         ๐ฆ๐ธ๐\n"
# define MISSEA "๐๐ธ๐ฆ        East texture line missing         ๐ฆ๐ธ๐\n"
# define MISSF "๐๐ธ๐ฆ         FLoor color line missing         ๐ฆ๐ธ๐\n"
# define MISSC "๐๐ธ๐ฆ        Ceiling color line missing        ๐ฆ๐ธ๐\n"
# define ENDFILE "๐๐ธ๐ฆ       Map must be the last element       ๐ฆ๐ธ๐\n"
# define DATAFAIL "๐๐ธ๐ฆ             Data Malloc fail             ๐ฆ๐ธ๐\n"
# define NORTHFAIL "๐๐ธ๐ฆ     Data North Texture Malloc fail       ๐ฆ๐ธ๐\n"
# define SOUTHFAIL "๐๐ธ๐ฆ     Data South Texture Malloc fail       ๐ฆ๐ธ๐\n"
# define WESTFAIL "๐๐ธ๐ฆ      Data West Texture Malloc fail       ๐ฆ๐ธ๐\n"
# define EASTFAIL "๐๐ธ๐ฆ      Data East Texture Malloc fail       ๐ฆ๐ธ๐\n"
# define FLOORFAIL "๐๐ธ๐ฆ         Data Floor RGB Malloc fail       ๐ฆ๐ธ๐\n"
# define CEILINGFAIL "๐๐ธ๐ฆ       Data Ceiling RGB Malloc fail       ๐ฆ๐ธ๐\n"
# define SUBTRIMFAIL "๐๐ธ๐ฆ           Sub trim Malloc fail           ๐ฆ๐ธ๐\n"
# define COMASFAIL "๐๐ธ๐ฆ     Split RGB on comas Malloc fail       ๐ฆ๐ธ๐\n"
# define MISSRGB "๐๐ธ๐ฆ     Missing RGB value, three needed      ๐ฆ๐ธ๐\n"
# define TMRGB "๐๐ธ๐ฆ     Too much RGB values, three needed    ๐ฆ๐ธ๐\n"
# define BIGRGB "๐๐ธ๐ฆ             RGB value too big            ๐ฆ๐ธ๐\n"
# define SYNTAXRGB "๐๐ธ๐ฆ          RGB value syntax error          ๐ฆ๐ธ๐\n"

# define OPENDIRNOTEX "๐๐ธ๐ฆ       North Texture is Directory         ๐ฆ๐ธ๐\n"
# define OPENDIRSOTEX "๐๐ธ๐ฆ       South Texture is Directory         ๐ฆ๐ธ๐\n"
# define OPENDIRWETEX "๐๐ธ๐ฆ       West Texture is Directory          ๐ฆ๐ธ๐\n"
# define OPENDIREATEX "๐๐ธ๐ฆ       East Texture is Directory          ๐ฆ๐ธ๐\n"
# define OPENNOTEX "๐๐ธ๐ฆ        Can't Open North Texture          ๐ฆ๐ธ๐\n"
# define OPENSOTEX "๐๐ธ๐ฆ        Can't Open South Texture          ๐ฆ๐ธ๐\n"
# define OPENWETEX "๐๐ธ๐ฆ        Can't Open West Texture           ๐ฆ๐ธ๐\n"
# define OPENEATEX "๐๐ธ๐ฆ        Can't Open East Texture           ๐ฆ๐ธ๐\n"

# define EMPTYNOTEX "๐๐ธ๐ฆ         North Texture is empty             ๐ฆ๐ธ๐\n"
# define EMPTYSOTEX "๐๐ธ๐ฆ         South Texture is empty             ๐ฆ๐ธ๐\n"
# define EMPTYWETEX "๐๐ธ๐ฆ         West Texture is empty              ๐ฆ๐ธ๐\n"
# define EMPTYEATEX "๐๐ธ๐ฆ         East Texture is empty              ๐ฆ๐ธ๐\n"
# define WNOEXT "๐๐ธ๐ฆ      Wrong North Texture Extension       ๐ฆ๐ธ๐\n"
# define WSOEXT "๐๐ธ๐ฆ      Wrong South Texture Extension       ๐ฆ๐ธ๐\n"
# define WWEEXT "๐๐ธ๐ฆ      Wrong West Texture Extension        ๐ฆ๐ธ๐\n"
# define WEAEXT "๐๐ธ๐ฆ      Wrong East Texture Extension        ๐ฆ๐ธ๐\n"
# define SIZENOTEX "๐๐ธ๐ฆ     North Texture sie is not 64 x 64     ๐ฆ๐ธ๐\n"
# define SIZESOTEX "๐๐ธ๐ฆ     South Texture sie is not 64 x 64     ๐ฆ๐ธ๐\n"
# define SIZEWETEX "๐๐ธ๐ฆ      West Texture sie is not 64 x 64     ๐ฆ๐ธ๐\n"
# define SIZEEATEX "๐๐ธ๐ฆ      East Texture sie is not 64 x 64     ๐ฆ๐ธ๐\n"
# define MLXFAIL "๐๐ธ๐ฆ      Mlx init fail (nice try env -i)     ๐ฆ๐ธ๐\n"
# define MAPFAIL "๐๐ธ๐ฆ           Map Malloc fail error          ๐ฆ๐ธ๐\n"
# define WCHARMAP "๐๐ธ๐ฆ     Map is not only ' 01NSWE' chars      ๐ฆ๐ธ๐\n"
# define SPLITMAP "๐๐ธ๐ฆ      Map is splitted by space line       ๐ฆ๐ธ๐\n"

# define NCLOSEDMAP "๐๐ธ๐ฆ        Map is not closed by 1 chars      ๐ฆ๐ธ๐\n"
# define ZEROPMAP "๐๐ธ๐ฆ             Map has no player            ๐ฆ๐ธ๐\n"
# define MULTIPMAP "๐๐ธ๐ฆ       Map has more than one player       ๐ฆ๐ธ๐\n"
# define GNLFAIL "๐๐ธ๐ฆ           Gnl Malloc fail error          ๐ฆ๐ธ๐\n"
# define SCREENFAIL "๐๐ธ๐ฆ           Screen Malloc fail error        ๐ฆ๐ธ๐\n"
# define IMGFAIL "๐๐ธ๐ฆ           Image Malloc fail error        ๐ฆ๐ธ๐\n"
# define TEXFAIL "๐๐ธ๐ฆ          Texture Malloc fail error        ๐ฆ๐ธ๐\n"
# define IMGTEXFAIL "๐๐ธ๐ฆ       Texture Image Malloc fail error     ๐ฆ๐ธ๐\n"
# define MLXINITFAIL "๐๐ธ๐ฆ     Mlx init fail (nice try env -i)      ๐ฆ๐ธ๐\n"
# define MLXWINFAIL "๐๐ธ๐ฆ          Mlx new window failed           ๐ฆ๐ธ๐\n"
# define MLXIMGFAIL "๐๐ธ๐ฆ           Mlx new image failed           ๐ฆ๐ธ๐\n"
# define MLXADDRFAIL "๐๐ธ๐ฆ         Mlx data address failed          ๐ฆ๐ธ๐\n"

# define MAPCHAR "01NSWE"

#endif
