/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/30 14:30:25 by fcatinau         ###   ########.fr       */
=======
/*   Updated: 2022/04/06 03:49:23 by fcatinau         ###   ########.fr       */
>>>>>>> restart_raycasting
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "error.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
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

/*
 FONCTIONS AUTORISEES:
open, cose, read, write, printf, malloc, free, perror, strerror, exit
toutes les fonctions de math.h
*/

/*
**--------------Define--------------
*/
# define WIDTH 1000
# define HEIGHT 500

/*
**---------------Enum---------------
*/

enum	e_player
{
	X_POS,
	Y_POS,
<<<<<<< HEAD
=======
	X_PIXEL,
	Y_PIXEL,
>>>>>>> restart_raycasting
	ANGLE,
	MAX_POS,
};

enum	e_img
{
	PLAYER,
	WALL_IMG,
	FLOOR_IMG,
	CEILING_IMG,
	MAX_IMG,
};

enum	e_type
{
	ERROR_TYPE = 0,
	EMPTY_LINE,
	TEXTURE_LINE,
	COLOR_LINE,
	MAP_LINE,
	ERROR_LINE,
};

enum	e_INFOS
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
};

// enum	e_MOVE
// {
// 	UP = 0,
// 	DOWN,
// 	LEFT,
// 	RIGHT
// };

enum	e_TEXTURE
{
	FLOORTEX = 0,
	CEILINGTEX,
	NORTHTEX,
	SOUTHTEX,
	WESTTEXT,
	EASTTEX,
};

enum	e_RGB
{
	RED_RGB = 0,
	GREEN_RGB,
	BLUE_RGB,
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
typedef struct s_tmp	t_tmp;
typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;
typedef struct s_rgb	t_rgb;
typedef struct s_list	t_list;
typedef struct s_mlx	t_mlx;

struct s_data
{
	char	**map;
	int		map_height;
	int		map_width;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb;
	int		ceiling_rgb;
};

struct s_list
{
	char	*line;
	int		line_size;
	int		type;
	t_list	*next;
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
<<<<<<< HEAD
	float	delta[2];// 0 = X | 1 = Y check if needed
	char	**map;
=======
	double	delta[2];
	t_data	*data;
>>>>>>> restart_raycasting
};

/*
**----------------------------------
**----------------MLX---------------
**----------------------------------
*/

<<<<<<< HEAD
void	start_mlx(char **file);
=======
void	start_mlx(t_data *data);
void	find_player_pos(char **tmp, t_mlx *mlx);
void	create_texture(t_mlx *mlx);
void	print_min_map(t_mlx *mlx);
/*
**-------------Check---------------
*/
double	vertical_check(t_mlx *mlx, double ra);
double	horizontal_check(t_mlx *mlx, double ra);

/*
**--------------Hook---------------
*/
int		key_hook(int key, t_mlx *mlx);
int		ft_close(t_mlx *mlx);

/*
**-------------Utils---------------
*/
double	dist(double ax, double ay, double bx, double by);
void	print_3d(t_mlx *mlx, int rayon, double ra, int *x);
void	mlx_print_line(t_mlx *mlx, int const a[2], int const b[2],
			int const color);

/*
**--------------Free---------------
*/
>>>>>>> restart_raycasting
void	free_mlx(t_mlx *mlx);

/*
**----------------------------------
**--------------UTILS---------------
**----------------------------------
*/
void	*ft_ternary(int const cond, void *valid_1, void *valid_2);

// parsing.c
void	parsing(int argc, char **arg, t_data **data);

// fill_list.c
void	fill_list(int fd, t_list **list);

// check_syntax.c
void	check_list_syntax(t_list **list);

// check_duplicates.c
void	check_list_duplicates(t_list **list);

// fill_data.c
void	fill_data(t_data **data, t_list **list);

// data_utils.c
void	init_data(t_data **data, t_list **list);

// check_textures.c
void	close_all_textures(int *fd);
void	check_open_textures(t_data **data);

// string_utils.c
int		ft_strlen(char *str);
int		is_digit(char c);
int		is_cardinal_char(char c);
int		is_color_char(char c);
char	*ft_strndup(char *str, int n);

// string_utils2.c
int		ft_strcmp(char *str1, char *str2);
int		ft_strncmp(char *str1, char *str2, unsigned int n);
int		set_line_type(char *str);
char	*ft_strchr(char *str, char c);
char	*sub_trim_str(char *str, char *set);

// ft_split.c
char	**ft_split(t_data **data, t_list **list, char *str, char c);

// atoi_base.c
int		ft_atoi_base(char *str, int str_base);
int		ft_atoi(char *str);

// lst_utils.c
int		ft_lst_size(t_list *list);
t_list	*ft_lst_create(char *line);
void	ft_lst_clear(t_list **list);
t_list	*ft_lstlast(t_list *list);
t_list	*ft_lst_addback(t_list **list, t_list *elem);

// tab_utils.c
int		nbrlen(char *str);
void	bzero_int_tab(int *tab, int tab_size, int value);
int		create_trgb(int t, int r, int g, int b);

// file_utils.c
void	check_open(char *filename, int *fd);
int		check_close(int fd, t_list *list);

// free.c
void	clear_list_exit(t_list **list, char *msg);
void	clear_list_syntax_exit(t_list **list, int i, char *line, char *msg);
void	clear_list_free_line_exit(t_list **list, char *line);
void	clear_data(t_data **data);

// free2.c
void	free_array(char **array);
void	clear_data(t_data **data);
void	clear_data_exit(t_data **data, char *msg);
void	clear_all_exit(t_data **data, t_list **list, char *msg);
void	clear_mlx_fd_data_exit(t_data **data, void *mlx, int *fd, char *msg);

// print.c
void	exit_error(char *msg);
void	print_list(t_list *list);
void	print_data(t_data *data);
void	print_map(char **map);
void	print_array(char **array);

// main.c
void	check_open(char *filename, int *fd);
int		check_close(int fd, t_list *list);

#endif
