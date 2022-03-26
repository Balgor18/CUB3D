/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:54:09 by grannou           #+#    #+#             */
/*   Updated: 2022/03/26 20:41:31 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/*
int		count_numbers(char *str)
{
	int	nbr_count;

	nbr_count = 0;
	while (str && *str)
	{
		if ((*str != ',') && (*(str + 1) == ',' || *(str + 1) == '\0'))
			nbr_count++;
		str++;
	}
	return (nbr_count);
}

int		ft_nbrlen(char *str)
{
	int	i;

	i = 0;
	while (*str && *str != ',')
		i++;
	return (i);
}

void	split_comas(t_data **data, t_list **list, char *str, char ***array)
{
	int	i;
	int	j;
	int	nbr_count;
	int	nbr_len;

	i = 0;
	printf("In split comas, str to split = [%s]\n", str);
	nbr_count = count_numbers(str);
	printf("In split comas, nbr_count = %d\n", nbr_count);
	nbr_len = 0;
	*array = (char **)malloc(sizeof(char *) * (nbr_count + 1));
	if (!*array)
		clear_all_exit(data, list, COMASFAIL);
	while (i < nbr_count)
	{
		while (*str == ',')
			str++;
		nbr_len = ft_nbrlen(str);
		printf("In split comas, nbr_len = %d\n", nbr_len);
		*array[i] = (char *)malloc(sizeof(char) * (nbr_len + 1));
		if (!*array[i])
		{
			free_array(*array);
			clear_all_exit(data, list, COMASFAIL);
		}
		j = 0;
		while (j < nbr_len)
			*array[i][j++] = *str++;
		*array[i][j] = '\0';
		i++;
	}
	*array[i] = NULL;
}
*/
int	get_hexa_rgb_value(t_data **data, t_list **list, char *str)
{
	char	**array;
	int		rgb[3];
	int		hexa_color;

	bzero_int_tab(rgb, 3, 0);
	hexa_color = 0;
	array = ft_split(str, ',');
	if (!array)
		clear_all_exit(data, list, COMASFAIL);
	print_array(array);
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
