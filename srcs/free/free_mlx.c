/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:10:22 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/08 16:29:13 by fcatinau         ###   ########.fr       */
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
	if (mlx->pict[IMAGE].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[IMAGE].img);
	if (mlx->pict[WALL_NORTH].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_NORTH].img);
	if (mlx->pict[WALL_SOUTH].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_SOUTH].img);
	if (mlx->pict[WALL_WEST].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_WEST].img);
	if (mlx->pict[WALL_EAST].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_EAST].img);
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
		mlx_destroy_display(mlx->mlx_ptr);
	clear_data(&mlx->data);
}
