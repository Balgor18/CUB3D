/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:03:13 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/19 20:17:11 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 2
# endif

enum e_error
{
	E_SUCCESS = 0,
	E_MALLOC_FAIL = -1,
	E_READ_FAIL = -2,
};

typedef struct s_gnl
{
	struct s_gnl	*next;
	char			buf[BUFF_SIZE];
}				t_gnl;

struct s_data
{
	size_t	line_size;
	size_t	rd_size;
	size_t	list_size;
	char	*ptrchr;

	int		error;
	t_gnl	*gnl;

};

struct s_mem
{
	char	str[BUFF_SIZE];
	size_t	size;
	int		status;
}		t_mem;

int		get_next_line(int fd, char **line, int reset);
int		ft_lstaddnew_front(struct s_data *data);
int		ft_no_newline_in_rest(struct s_data *data,
			struct s_mem *rest, char **line);

void	ft_cpy_buffer_list_free(t_gnl **gnl, char *line, size_t len_cpy);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *pointeur, int val, size_t size);
void	ft_lstdelall(t_gnl **lst);

#endif