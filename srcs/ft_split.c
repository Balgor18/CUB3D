/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:23:53 by grannou           #+#    #+#             */
/*   Updated: 2022/04/03 01:12:31 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_words(char *str, char c)
{
	int		wcount;

	wcount = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == '\0' || *(str + 1) == c))
			wcount++;
		str++;
	}
	return (wcount);
}

static int	ft_wordlen(char *str, char c)
{
	int		wlen;

	wlen = 0;
	while (str[wlen] && str[wlen] != c)
		wlen++;
	return (wlen);
}

static void	*ft_free(char **words, int wcount)
{
	while (wcount--)
		free(words[wcount]);
	free(words);
	return (NULL);
}

static char	**fill(char *str, int wcount, char c, char **words)
{
	int		i;
	int		j;
	int		wlen;

	i = 0;
	while (i < wcount)
	{
		while (*str == c)
			str++;
		wlen = ft_wordlen(str, c);
		words[i] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (!words[i])
			return (ft_free(words, i));
		j = 0;
		while (j < wlen)
			words[i][j++] = *str++;
		words[i][j] = '\0';
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(t_data **data, t_list **list, char *str, char c)
{
	char	**words;
	int		wcount;

	if (!str)
		return (NULL);
	wcount = count_words(str, c);
	if (wcount != 3)
	{
		if (wcount < 3)
		{
			free(str);
			clear_all_exit(data, list, MISSRGB);
		}
		if (wcount > 3)
		{
			free(str);
			clear_all_exit(data, list, TMRGB);
		}
	}
	words = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!words)
		return (NULL);
	words = fill(str, wcount, c, words);
	return (words);
}
