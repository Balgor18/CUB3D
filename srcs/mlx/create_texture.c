/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 05:00:40 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/06 19:42:20 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	xpm_file_and_addr(void *mlx_ptr, t_img *img, int byte)
{
	size_t	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT / 2);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->bits_per_pixel, &img->endian);
	// do verif | PAS DE EXIT
	while (i < WIDTH * (HEIGHT / 2))
	{
		img->addr[i] = byte;
		i++;
	}
}

static void	xpm_texture_and_addr(void *mlx_ptr, char *txt_name, t_img *img)
{
	img->img = mlx_xpm_to_image(mlx_ptr, txt_name, &img->width, &img->height);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	// do verif | PAS DE EXIT
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
	xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[CEILING_IMG],
		mlx->data->ceiling_rgb);// continue verif | PAS DE EXIT
	xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[FLOOR_IMG],
		mlx->data->floor_rgb);// continue verif | PAS DE EXIT
	xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->north_texture,
		&mlx->pict[WALL_NORTH]);// continue verif | PAS DE EXIT
	xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->south_texture,
		&mlx->pict[WALL_SOUTH]);// continue verif | PAS DE EXIT
	xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->west_texture,
		&mlx->pict[WALL_WEST]);// continue verif | PAS DE EXIT
	xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->east_texture,
		&mlx->pict[WALL_EAST]);// continue verif | PAS DE EXIT
}
