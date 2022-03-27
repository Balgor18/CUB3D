/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:54:09 by grannou           #+#    #+#             */
/*   Updated: 2022/03/27 20:14:49 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	nbrlen(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (is_digit(*str))
	{
		i++;
		str++;
	}
	while (*str == ' ')
		str++;
	if (is_digit(*str))
		return (-1);
	return (i);
}

void	check_value_limits(t_data **data, t_list **list, char **array)
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
		if (len == -1)
			clear_all_exit(data, list, SYNTAXRGB);
		if (len > 3)
			clear_all_exit(data, list, BIGRGB);
		nbr = ft_atoi(array[i]);
		if (nbr > 255)
			clear_all_exit(data, list, BIGRGB);
		i++;
	}
}

int	get_hexa_rgb_value(t_data **data, t_list **list, char *str)
{
	char	**array;
	int		rgb[3];
	int		hexa_color;

	bzero_int_tab(rgb, 3, 0);
	hexa_color = 0;
	array = ft_split(data, list, str, ',');
	if (!array)
		clear_all_exit(data, list, COMASFAIL);
	print_array(array);
	check_value_limits(data, list, array);
	free_array(array);
	return (hexa_color);
}

static void	fill_rgb(t_data **data, t_list **list, int *dest, char *src)
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
			if (!to_split && (ft_strcmp(src, "F ") == 0))
				clear_all_exit(data, list, FLOORFAIL);
			if (!to_split && (ft_strcmp(src, "C ") == 0))
				clear_all_exit(data, list, CEILINGFAIL);
			*dest = get_hexa_rgb_value(data, list, to_split);
			free(to_split);
		}
		tmp = tmp->next;
	}
}

static void	fill_texture(t_data **data, t_list **list, char **dest, char *src)
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

void	fill_data(t_data **data, t_list **list)
{
	init_data(data, list);
	fill_texture(data, list, &(*data)->north_texture, "NO ");
	fill_texture(data, list, &(*data)->south_texture, "SO ");
	fill_texture(data, list, &(*data)->west_texture, "WE ");
	fill_texture(data, list, &(*data)->east_texture, "EA ");
	fill_rgb(data, list, &(*data)->floor_rgb, "F ");
	fill_rgb(data, list, &(*data)->ceiling_rgb, "C ");
}
