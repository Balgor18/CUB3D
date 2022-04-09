/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/09 20:33:59 by fcatinau         ###   ########.fr       */
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
# include <X11/X.h>
# include <stdio.h>
# include "mlx.h"
# include <stdbool.h>
# include "key_linux.h"

/*
 FONCTIONS AUTORISEES:
open, cose, read, write, printf, malloc, free, perror, strerror, exit
toutes les fonctions de math.h
*/

/*
**--------------Define--------------
*/
# define WIDTH 1024
// # define WIDTH 683
# define HEIGHT 384

/*
**---------------Enum---------------
*/

enum	e_player
{
	X_POS,
	Y_POS,
	X_PIXEL,
	Y_PIXEL,
	ANGLE,
	MAX_POS,
};

enum	e_img
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST,
	IMAGE,
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
**--------------struct--------------
*/
typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;
typedef struct s_list	t_list;
typedef struct s_rayon	t_rayon;

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
	int		player_x;
	int		player_y;
	char	player_dir;
	float	player_dir_radian;
};

struct s_list
{
	char	*line;
	int		line_size;
	int		type;
	t_list	*next;
};

struct s_rayon
{
	float	dist;
	double	angle;
	int		type;
	double	end_pos[2];
};

struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	pict[MAX_IMG];
	double	player[MAX_POS];
	double	delta[2];
	t_rayon	rayon[WIDTH];
	t_data	*data;
};

/*
**----------------------------------
**----------------MLX---------------
**----------------------------------
*/

void	start_mlx(t_data *data);
void	find_player_pos(char **tmp, t_mlx *mlx);
void	create_texture(t_mlx *mlx);
void	print_min_map(t_mlx *mlx);
void	print_nord(t_img *const img[2], t_rayon const *const rayon, float i[4]);
void	print_south(t_img *const img[2], t_rayon const *const rayon,
			float i[4]);
void	print_west(t_img *const img[2], t_rayon const *const rayon, float i[4]);
void	print_east(t_img *const img[2], t_rayon const *const rayon, float i[4]);

/*
**-------------Check---------------
*/
double	vertical_check(t_mlx *mlx, double ra, double *end_pos);
double	horizontal_check(t_mlx *mlx, double ra, double *end_pos);

/*
**--------------Hook---------------
*/
int		key_hook(int key, t_mlx *mlx);
int		ft_close(t_mlx *mlx);

/*
**-------------Utils---------------
*/
double	dist(double ax, double ay, double bx, double by);
void	print_3d(t_mlx *const mlx, t_rayon *const rayon, double ra, int *x)
		__attribute__((nonnull));
void	mlx_print_line(t_mlx *mlx, int const a[2], int const b[2],
			int const color);

/*
**--------------Free---------------
*/
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
void	check_splitted_map(t_list **list);

// check_duplicates.c
void	check_list_duplicates(t_list **list);

// fill_data.c
void	fill_data(t_data **data, t_list **list);

// data_utils.c
void	init_data(t_data **data, t_list **list);
void	*ft_memset(void *b, int c, int len);
void	check_player_count(t_data **data);
void	get_player_infos(t_data **data);

// check_closed_map.c
void	check_closed_map(t_data **data);

// fill_textures.c
void	fill_rgb(t_data **data, t_list **list, int *dest, char *str);
void	fill_texture(t_data **data, t_list **list, char **dest, char *src);

// check_textures.c
void	check_textures_extensions(t_data **data);
void	close_all_textures(int *fd);
void	close_error_exit(t_data **data, int *fd);
void	close_dir_error_exit(t_data **data, int *fd);
void	check_open_textures(t_data **data);

// string_utils.c
int		ft_strlen(char *str);
int		is_digit(char c);
int		is_cardinal_char(char c);
int		is_color_char(char c);
int		is_map_str(char *str);
char	*ft_strndup(char *str, int n);

// string_utils2.c
int		ft_strcmp(char *str1, char *str2);
int		ft_strncmp(char *str1, char *str2, unsigned int n);
int		set_line_type(char *str);
char	*ft_strchr(char *str, char c);

// string_utils3.c
char	*sub_trim_str(char *str, char *set);
int		check_extension(char *str, char *ext);

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
void	open_all_textures(t_data **data, int *fd, void *mlx);
void	open_all_dir_textures(t_data **data, int *fd, void *mlx);
int		check_close(int fd, t_list *list);
void	close_all_textures(int *fd);

// free.c
void	clear_list_exit(t_list **list, char *msg);
void	clear_list_syntax_exit(t_list **list, int i, char *line, char *msg);
void	clear_data_syntax_exit(t_data **data, int i, char *line, char *msg);
void	clear_list_free_line_exit(t_list **list, char *line);
void	clear_data_nclosedmap_exit(t_data **data, int i, char *msg);

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
