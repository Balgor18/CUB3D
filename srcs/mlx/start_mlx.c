/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:35:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 20:07:14 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// 0 = HEIGHT
// 1 = WIDTH;
// static void	print_map(t_tmp *file, t_mlx mlx)
// {
// 	int	i[2];

// 	(void)file;
// 	(void)mlx;
// 	(void)i;
// 	// while ()
// }

// pos[0] = X;
// pos[1] = Y;
static bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return true;
	return false;
}

static void	find_player_pos(t_tmp *tmp, t_mlx *mlx)
{
	int	pos[2];

	pos[1] = 1;// see if need to start 1
	while (tmp)
	{
		pos[0] = 1;// see if need to start 1
		while (*(tmp->line))
		{
			if (is_player(*(tmp->line)))
			{
				mlx->player[X_POS] = pos[0];
				mlx->player[Y_POS] = pos[1];
				return ;
			}
			pos[0]++;
			tmp->line++;
		}
		pos[1]++;
		tmp = tmp->next;
	}
}

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(char *)dst = color;
}

// i[0] = X
// i[1] = Y
static void	draw_player(t_mlx *mlx)
{
	int	i[2];
	int	tmp;

	i[0] = (mlx->player[X_POS] * 64) - 8;
	i[1] = (mlx->player[Y_POS] * 64) - 8;

	while (i[1] < (mlx->player[Y_POS] * 64) + 8)
	{
		tmp = (mlx->player[X_POS] * 64) - 8;
		while (tmp < (mlx->player[X_POS] * 64) + 8)
		{
			printf("[%d] [%d] player pos\n", i[1], tmp);
			my_mlx_pixel_put(&mlx->pict, tmp, i[1], 0x00F280FFFF);
			tmp++;
		}
		i[1]++;
	}
}
// 0x00F280FF
// 0x0000FF00
// 0x000000FF
// 0x0000FF --> BLUE
// 0x00FF00 --> Nothing
// 0xFF0000 --> Nothing
void	start_mlx(t_tmp *file)
{
	t_mlx	mlx;
	int		width;
	int		height;

	width = 64 * 16;
	height = 6 * 64;

	mlx = (t_mlx){0};
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, width, height, "Test win");//16 | 6
	if (!mlx.win_ptr)
		return (mlx_destroy_display(mlx.mlx_ptr), free(mlx.mlx_ptr));
	mlx.pict.img = mlx_new_image(mlx.mlx_ptr, width, height);
	if (!mlx.pict.img)
		return (mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr), mlx_destroy_display(mlx.mlx_ptr), free(mlx.mlx_ptr));
	// print_map(file, mlx);
	// mlx.pict.addr = (int *)mlx_get_data_addr(mlx.pict.img, &mlx.pict.bits_per_pixel, &mlx.pict.line_length, &mlx.pict.endian);
	mlx.pict.addr = mlx_get_data_addr(mlx.pict.img, &mlx.pict.bits_per_pixel, &mlx.pict.line_length, &mlx.pict.endian);
	find_player_pos(file, &mlx);
	printf("x = %f\ny = %f\n", mlx.player[X_POS], mlx.player[Y_POS]);
	draw_player(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.pict.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	// mlx;
}
