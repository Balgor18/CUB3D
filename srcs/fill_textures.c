/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:52:05 by grannou           #+#    #+#             */
/*   Updated: 2022/04/06 17:51:13 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void
	check_value_limits(t_data **data, t_list **list, char **array, char **str)
{
	int	i;
	int	len;
	int	nbr;

	i = 0;
	len = 0;
	nbr = 0;
	while (array && array[i])
	{
		len = 0;
		len = nbrlen(array[i]);
		nbr = ft_atoi(array[i]);
		if (len == -1 || len > 3 || nbr > 255)
		{
			free(*str);
			free_array(array);
			if (len == -1)
				clear_all_exit(data, list, SYNTAXRGB);
			if (len > 3)
				clear_all_exit(data, list, BIGRGB);
			if (nbr > 255)
				clear_all_exit(data, list, BIGRGB);
		}
		i++;
	}
}

static int	get_hexa_rgb_value(t_data **data, t_list **list, char **str)
{
	char	**array;
	int		rgb[3];
	int		hexa_color;

	bzero_int_tab(rgb, 3, 0);
	hexa_color = 0;
	array = ft_split(data, list, *str, ',');
	if (!array)
	{
		free(str);
		clear_all_exit(data, list, COMASFAIL);
	}
	check_value_limits(data, list, array, str);
	rgb[RED_RGB] = ft_atoi(array[RED_RGB]);
	rgb[GREEN_RGB] = ft_atoi(array[GREEN_RGB]);
	rgb[BLUE_RGB] = ft_atoi(array[BLUE_RGB]);
	hexa_color = create_trgb(0, rgb[RED_RGB], rgb[GREEN_RGB], rgb[BLUE_RGB]);
	free_array(array);
	return (hexa_color);
}

void	fill_rgb(t_data **data, t_list **list, int *dest, char *src)
{
	t_list	*tmp;
	char	*to_split;

	tmp = *list;
	to_split = NULL;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, src, 2) == 0)
		{
			to_split = sub_trim_str(tmp->line, src);
			if (!to_split)
			{
				if (ft_strcmp(src, "F ") == 0)
					clear_all_exit(data, list, FLOORFAIL);
				else if (ft_strcmp(src, "C ") == 0)
					clear_all_exit(data, list, CEILINGFAIL);
			}
			*dest = get_hexa_rgb_value(data, list, &to_split);
			free(to_split);
		}
		tmp = tmp->next;
	}
}

void	fill_texture(t_data **data, t_list **list, char **dest, char *src)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, src, 3) == 0)
		{
			*dest = sub_trim_str(tmp->line, src);
			if (!*dest && (ft_strcmp(src, "NO ") == 0))
				clear_all_exit(data, list, NORTHFAIL);
			else if (!*dest && (ft_strcmp(src, "SO ") == 0))
				clear_all_exit(data, list, SOUTHFAIL);
			else if (!*dest && (ft_strcmp(src, "WE ") == 0))
				clear_all_exit(data, list, WESTFAIL);
			else if (!*dest && (ft_strcmp(src, "EA ") == 0))
				clear_all_exit(data, list, EASTFAIL);
		}
		tmp = tmp->next;
	}
}
