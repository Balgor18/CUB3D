/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:29:16 by grannou           #+#    #+#             */
/*   Updated: 2022/03/22 11:39:38 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_lst_size(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_list	*ft_lst_create(char *line)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->line = line;
	elem->line_size = ft_strlen(elem->line);
	elem->type = set_line_type(elem->line);
	elem->next = NULL;
	return (elem);
}

void	ft_lst_clear(t_list **list)
{
	t_list	*ptr;
	t_list	*next;

	ptr = *list;
	while (ptr)
	{
		next = ptr->next;
		free(ptr->line);
		free(ptr);
		ptr = next;
	}
}

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_list	*ft_lst_addback(t_list **list, t_list *elem)
{
	if (*list)
		ft_lstlast(*list)->next = elem;
	else
		*list = elem;
	return (*list);
}
