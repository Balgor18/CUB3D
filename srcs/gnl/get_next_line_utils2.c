/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:05:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/11/06 18:34:34 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstaddnew_front(struct s_data *data)
{
	t_gnl	*new_elem;

	new_elem = malloc(sizeof(t_gnl));
	if (!new_elem)
	{
		data->error = E_MALLOC_FAIL;
		return (0);
	}
	*new_elem = (t_gnl){0};
	new_elem->next = data->gnl;
	data->gnl = new_elem;
	return (1);
}

void	ft_cpy_buffer_list_free(t_gnl **gnl, char *line, size_t len_cpy)
{
	t_gnl	*tmp;

	if (*(*gnl)->buf == '\0' && (len_cpy % BUFF_SIZE) != 0)
	{
		tmp = (*gnl)->next;
		free(*gnl);
		*gnl = tmp;
	}
	if (*gnl)
	{
		ft_memcpy(line - (len_cpy % BUFF_SIZE), (*gnl)->buf,
			len_cpy % BUFF_SIZE);
		line -= len_cpy % BUFF_SIZE;
		tmp = (*gnl)->next;
		free(*gnl);
		*gnl = tmp;
	}
	while (*gnl)
	{
		ft_memcpy(line - BUFF_SIZE, (*gnl)->buf, BUFF_SIZE);
		line -= BUFF_SIZE;
		tmp = (*gnl)->next;
		free(*gnl);
		*gnl = tmp;
	}
}

int	ft_no_newline_in_rest(struct s_data *data, struct s_mem *rest, char **line)
{
	data->ptrchr = ft_memchr(rest->str, '\n', rest->size);
	if (!data->ptrchr && rest->status)
		return (1);
	else if (data->ptrchr)
		data->line_size = data->ptrchr - rest->str;
	else
	{
		data->line_size = rest->size;
		return (1);
	}
	*line = malloc(sizeof(char) * (data->line_size + 1));
	if (!*line)
	{
		data->error = E_MALLOC_FAIL;
		return (-1);
	}
	ft_memcpy(*line, rest->str, data->line_size);
	(*line)[data->line_size] = '\0';
	rest->size = rest->size - data->line_size - 1;
	ft_memmove(rest->str, rest->str + data->line_size + 1, rest->size);
	return (0);
}
