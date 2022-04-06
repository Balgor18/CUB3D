/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 05:00:40 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/06 21:08:40 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	xpm_file_and_addr(void *mlx_ptr, t_img *img, int byte)
{
	size_t	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT / 2);
	if (!img->img)
		return (EXIT_FAILURE);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	while (i < WIDTH * (HEIGHT / 2))
	{
		img->addr[i] = byte;
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	xpm_texture_and_addr(void *mlx_ptr, char *txt_name, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, txt_name, &img->width,
			&img->height);
	if (!img->img)
		return (EXIT_FAILURE);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (EXIT_SUCCESS);
}

/**
 * @brief	Function create all the texture
 *
 * @param	t_mlx	All the informations we need for create the texture
 *
 * @return	return void
**/
void	create_texture(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	if (!mlx->win_ptr)
		return (free_mlx(mlx));
	if (xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[CEILING_IMG],
			mlx->data->ceiling_rgb))
		return (free_mlx(mlx));
	if (xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[FLOOR_IMG],
			mlx->data->floor_rgb))
		return (free_mlx(mlx));
	if (xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->north_texture,
			&mlx->pict[WALL_NORTH]))
		return (free_mlx(mlx));
	if (xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->south_texture,
			&mlx->pict[WALL_SOUTH]))
		return (free_mlx(mlx));
	if (xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->west_texture,
			&mlx->pict[WALL_WEST]))
		return (free_mlx(mlx));
	if (xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->east_texture,
			&mlx->pict[WALL_EAST]))
		return (free_mlx(mlx));
}
