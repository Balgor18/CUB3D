/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:16:50 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 11:45:00 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *str, int n)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (n + 1));
	if (!new_str)
		return (NULL);
	while (i < n)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	is_cardinal_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	is_color_char(char c)
{
	return (c == 'F' || c == 'C');
}

int	set_line_type(char *str)
{
	int	type;

	type = 0;
	if (str[0] == '\0')
		type = EMPTY_LINE;
	else if (is_cardinal_char(str[0]))
		type = TEXTURE_LINE;
	else if (is_color_char(str[0]))
		type = COLOR_LINE;
	else if (str[0] == ' ' || str[0] == '0' || str[0] == '1')
		type = MAP_LINE;
	return (type);
}