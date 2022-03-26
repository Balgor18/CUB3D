/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/26 14:15:10 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

enum	e_TYPE
{
	ERROR_TYPE = 0,
	EMPTY_LINE,
	TEXTURE_LINE,
	COLOR_LINE,
	MAP_LINE,
	ERROR_LINE
};

enum	e_INFOS
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING
};

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
typedef struct s_list	t_list;
typedef struct s_mlx	t_mlx;

struct s_data
{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb; // Un seul INT en hexa style 0xFF000FF
	int		ceiling_rgb;// pareil
};

struct s_list
{
	char	*line;
	int		line_size;
	int		type;
	t_list	*next;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
};

// parsing.c
void	parsing(int argc, char **arg, t_data **data);

// check_syntax.c
void	check_list_syntax(t_list **list);

// check_duplicates.c
void	check_list_duplicates(t_list **list);

// fill_list.c
void	fill_list(int fd, t_list **list);

// fill_data.c
void	fill_data(t_data **data, t_list **list);

// data_utils.c
void	init_data(t_data **data, t_list **list);

// string_utils.c
int		ft_strlen(char *str);
int		is_cardinal_char(char c);
int		is_color_char(char c);
char	*ft_strchr(char *str, char c);
char	*sub_trim_str(char *str, char *set);

// string_utils2.c
char	*ft_strndup(char *str, int n);
int		ft_strcmp(char *str1, char *str2);
int		ft_strncmp(char *str1, char *str2, unsigned int n);
int		set_line_type(char *str);

// atoi_base.c
int		ft_atoi_base(char *str, int str_base);

// lst_utils.c
int		ft_lst_size(t_list *list);
t_list	*ft_lst_create(char *line);
void	ft_lst_clear(t_list **list);
t_list	*ft_lstlast(t_list *list);
t_list	*ft_lst_addback(t_list **list, t_list *elem);

// tab_utils.c
void	bzero_int_tab(int *tab, int tab_size, int value);

// file_utils.c
void	check_open(char *filename, int *fd);
int		check_close(int fd, t_list *list);


// free.c
void	clear_list_exit(t_list **list, char *msg);
void	clear_list_syntax_exit(t_list **list, int i, char *line, char *msg);
void	clear_list_free_line_exit(t_list **list, char *line);
void	free_map(char **map);
void	clear_data(t_data **data);
void	clear_all_exit(t_data **data, t_list **list, char *msg);

// print.c
void	exit_error(char *msg);
void	print_list(t_list *list);
void	print_data(t_data *data);

// main.c
void	check_open(char *filename, int *fd);
int		check_close(int fd, t_list *list);

#endif
