/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/22 23:43:10 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return true;
	return false;
}

// pos[0] = X;
// pos[1] = Y;
static void	find_player_pos(t_tmp *tmp, t_mlx *mlx)
{
	int	pos[2];
	t_tmp	*tmpb;
	char	*s;

	tmpb = tmp;
	pos[1] = 1;// see if need to start 1
	while (tmp)
	{
		pos[0] = 1;// see if need to start 1
		s = tmp->line;
		while (*s)
		{
			if (is_player(*s))
			{
				*s = '0';
				mlx->player[X_POS] = pos[0];
				mlx->player[Y_POS] = pos[1];
				return ;
			}
			pos[0]++;
			s++;
		}
		pos[1]++;
		tmp = tmp->next;
	}
	tmp = tmpb;
}

// 0x00FFFF00
// 0x00FF00FF

// 0x00FF0000 --> Nothing
// 0x00FFFFFF --> Blue Again
// 0x000000FF --> Blue
// 0x00000F00 --> Nothing

// 0xTTRRGGBB
// 0x00F280FF --> BLUE
// 0x0000FF00 --> Nothing
// 0x000000FF --> BLUE
// 0x0000FF --> BLUE
// 0x00FF00 --> Nothing
// 0xFF0000 --> Nothing
// 0x00FF4D00

static void	xpm_file_and_addr(void *mlx_ptr, t_img *img, int byte)
{
	int	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, 64, 64);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->bits_per_pixel, &img->endian);
	while (i < 4096)
	{
		img->addr[i] = byte;
		i++;
	}
}

static void	xpm_file_and_addr_player(void *mlx_ptr, t_img *img, int byte)
{
	int	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, 16, 16);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->bits_per_pixel, &img->endian);
	while (i < 256)
	{
		img->addr[i] = byte;
		i++;
	}
}

/**
 * @brief	Function create all the texture
 *
 * @param	t_mlx	All the informations we need for create the texture
 *
 * @return	return void
**/
static void	create_texture(t_mlx *mlx)
{
	int		width;
	int		height;

	width = 64 * 16;
	height = 6 * 64;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, "Test win");
	if (!mlx->win_ptr)
		return (free_mlx(mlx));

	xpm_file_and_addr_player(mlx->mlx_ptr, &mlx->pict[PLAYER], 0x0000FF00);
	xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[WALL], 0x000000FF);
	xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[FLOOR], 0x00FFFFFF);
	// xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[CEILING], 0x00000000);
}

static void	player_move(t_mlx *mlx, char move)
{
	if (move == 'R')// move this for ptr fct
		mlx->player[X_POS] += 0.1;
	else if (move == 'L')// move this for ptr fct
		mlx->player[X_POS] -= 0.1;
	else if (move == 'U')// move this for ptr fct
		mlx->player[Y_POS] -= 0.1;
	else if (move == 'D')// move this for ptr fct
		mlx->player[Y_POS] += 0.1;
}

//	i[0] == Y
//	i[1] == X
static void	print_min_map(t_mlx *mlx)
{
	t_tmp *tmp;
	char	*s;
	int		in[2];

	in[0] = 0;
	tmp = mlx->file;
	while (mlx->file)
	{
		s = mlx->file->line;
		in[1] = 0;
		printf("s = %s\n", s);
		while (*s)
		{
			printf("%c Y = %d x = %d\n", *s,  in[0], in[1]);
			if (*s == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[WALL].img, in[1], in[0]);
			else if (*s == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[FLOOR].img, in[1], in[0]);
			s++;
			in[1] += 64;
		}
		in[0] += 64;
		mlx->file = mlx->file->next;
	}
	mlx->file = tmp;
	//player
	int	i[2];

	i[0] = (mlx->player[X_POS] * 64) - 40;
	i[1] = (mlx->player[Y_POS] * 64) - 40;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->pict[PLAYER].img, i[0], i[1]);
}

static int	key_hook(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
	{
		// if (mlx->map.player.move != 0)
		// 	ft_putchar_fd('\n', 1);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		free_mlx(mlx);
		exit(0);
	}
	else if (key == D || key == RIGHT)
		player_move(mlx, 'R');
	else if (key == A || key == Q || key == LEFT)
		player_move(mlx, 'L');
		// press_move(all, &all->map, 'L');
	else if (key == S || key == DOWN)
		player_move(mlx, 'D');
		// press_move(all, &all->map, 'D');
	else if (key == W || key == Z || key == UP)
		player_move(mlx, 'U');
		// press_move(all, &all->map, 'U');
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	print_min_map(mlx);
	return (0);
}

static int	ft_close(t_mlx *mlx)
{
	// mlx_do_key_autorepeaton(all->mlx.mlx);
	// ft_trash(all);
	(void)mlx;
	exit(0);
	return (0);
}

/**
	@brief	Function start to create the mlx for the graphics

	@param	t_tmp	Take in param all the info from the parsing

	@return	Return void
 **/
void	start_mlx(t_tmp *file)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.file = file;
	find_player_pos(file, &mlx);
	create_texture(&mlx);

	print_min_map(&mlx);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.pict[WALL].img, 0, 0);
	
	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_hook, &mlx);

	// mlx_hook(mlx.mlx_win, 15, 1L << 16, reset_window, all);

	mlx_hook(mlx.win_ptr, 33, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
