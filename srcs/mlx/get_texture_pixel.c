/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:36:00 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/09 04:33:57 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifdef X
# undef X
#endif

#ifdef Y
# undef Y
#endif

#define X 0
#define Y 1
#define LINE_H 2
#define CEIL_H 3
#define WINDOW 0
#define TEXTURE 1

void	print_nord(t_img *const img[2], t_rayon const *const rayon, float i[4])
{
	int	pos[2];
	int	tmp;

	tmp = i[CEIL_H];
	if (i[LINE_H] > HEIGHT)
		i[CEIL_H] = HEIGHT;
	else
		i[CEIL_H] += i[LINE_H];
	pos[X] = (int)rayon->end_pos[X] % 64;
	while (i[Y] < i[CEIL_H])
	{
		pos[Y] = (i[Y] - tmp) * 64 / i[LINE_H];
		img[WINDOW]->addr[(int)(i[Y] * WIDTH + i[X])]
			= img[TEXTURE]->addr[pos[Y] * 64 + pos[X]];
		i[Y]++;
	}
}

void	print_south(t_img *const img[2], t_rayon const *const rayon, float i[4])
{
	int	pos[2];
	int	tmp;

	tmp = i[CEIL_H];
	if (i[LINE_H] > HEIGHT)
		i[CEIL_H] = HEIGHT;
	else
		i[CEIL_H] += i[LINE_H];
	pos[X] = 64 - (int)rayon->end_pos[X] % 64 - 1;
	while (i[Y] < i[CEIL_H])
	{
		pos[Y] = (i[Y] - tmp) * 64 / i[LINE_H];
		img[WINDOW]->addr[(int)(i[Y] * WIDTH + i[X])]
			= img[TEXTURE]->addr[pos[Y] * 64 + pos[X]];
		i[Y]++;
	}
}

void	print_west(t_img *const img[2], t_rayon const *const rayon, float i[4])
{
	int	pos[2];
	int	tmp;

	tmp = i[CEIL_H];
	if (i[LINE_H] > HEIGHT)
		i[CEIL_H] = HEIGHT;
	else
		i[CEIL_H] += i[LINE_H];
	pos[X] = 64 - (int)rayon->end_pos[Y] % 64 - 1;
	while (i[Y] < i[CEIL_H])
	{
		pos[Y] = (i[Y] - tmp) * 64 / i[LINE_H];
		img[WINDOW]->addr[(int)(i[Y] * WIDTH + i[X])]
			= img[TEXTURE]->addr[pos[Y] * 64 + pos[X]];
		i[Y]++;
	}
}

void	print_east(t_img *const img[2], t_rayon const *const rayon, float i[4])
{
	int	pos[2];
	int	tmp;

	tmp = i[CEIL_H];
	if (i[LINE_H] > HEIGHT)
		i[CEIL_H] = HEIGHT;
	else
		i[CEIL_H] += i[LINE_H];
	pos[X] = (int)rayon->end_pos[Y] % 64;
	while (i[Y] < i[CEIL_H])
	{
		pos[Y] = (i[Y] - tmp) * 64 / i[LINE_H];
		img[WINDOW]->addr[(int)(i[Y] * WIDTH + i[X])]
			= img[TEXTURE]->addr[pos[Y] * 64 + pos[X]];
		i[Y]++;
	}
}
