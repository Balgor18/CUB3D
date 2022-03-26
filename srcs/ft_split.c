/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:23:53 by grannou           #+#    #+#             */
/*   Updated: 2022/03/26 20:27:23 by grannou          ###   ########.fr       */
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

/*
** This function count the length of a word. Here a word means a bag of
** consecutive characters that are not c
*/
static int	ft_wordlen(char *str, char c)
{
	int		wlen;

	wlen = 0;
	while (str[wlen] && str[wlen] != c)
		wlen++;
	return (wlen);
}

/*
** This function free() the array of words backwardly in the case the malloc()
** of a word in the array failed, it recursively free() each previous word then
** it free() the array
*/
static void	*ft_free(char **words, int wcount)
{
	while (wcount--)
		free(words[wcount]);
	free(words);
	return (NULL);
}

/*
** This function fills the word count words in the array. If a word malloc()
** failed, all previous words and the array are freed. The array, as each word
** string, is null-terminated
*/
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

/*
** This function count the separated by c character words in string s. It
** allocates an array of word count size + 1 (for terminating '\0'). Then it
** fills the array with each word and return the array of splitted words.
*/
char	**ft_split(char *str, char c)
{
	char	**words;
	int		wcount;

	if (!str)
		return (NULL);
	wcount = count_words(str, c);
	words = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!words)
		return (NULL);
	words = fill(str, wcount, c, words);
	return (words);
}
