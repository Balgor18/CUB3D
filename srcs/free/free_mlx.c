/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:10:22 by fcatinau          #+#    #+#             */
<<<<<<< HEAD:srcs/mlx/free_mlx.c
/*   Updated: 2022/03/24 02:33:43 by fcatinau         ###   ########.fr       */
=======
/*   Updated: 2022/04/06 03:33:48 by fcatinau         ###   ########.fr       */
>>>>>>> restart_raycasting:srcs/free/free_mlx.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
	@brief	Free the texture contains in t_mlx

	@param	t_mlx The t_mlx struct contains all the info for mlx.

	@return	Return void
**/
static void	free_texture(t_mlx *mlx)
{
	if (mlx->pict[PLAYER].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[PLAYER].img);
	if (mlx->pict[WALL_IMG].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_IMG].img);
	if (mlx->pict[FLOOR_IMG].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[FLOOR_IMG].img);
	if (mlx->pict[CEILING_IMG].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[CEILING_IMG].img);
}

/**
	@brief	Free the struct t_mlx

	@param	t_mlx The t_mlx struct contains all the info for mlx.

	@return	Return void
**/
void	free_mlx(t_mlx *mlx)
{
	free_texture(mlx);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
<<<<<<< HEAD:srcs/mlx/free_mlx.c
		free(mlx->mlx_ptr);
	}
=======
	clear_data(&mlx->data);
>>>>>>> restart_raycasting:srcs/free/free_mlx.c
}
