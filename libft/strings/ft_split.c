/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:46:17 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/25 02:39:55 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *s, char delimiter)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s && *s == delimiter)
			++s;
		if (!*s)
			break ;
		while (*s && *s != delimiter)
			++s;
		++words;
	}
	return (words);
}

static void	*free_all(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

char	**ft_split(const char *s, char delimiter)
{
	char	**words;
	char	**start;
	size_t	word_count;
	size_t	word_len;

	word_count = count_words(s, delimiter);
	words = malloc(sizeof(*words) * (word_count + 1));
	if (!words)
		return (NULL);
	start = words;
	words[word_count] = NULL;
	while (word_count--)
	{
		while (*s && *s == delimiter)
			++s;
		word_len = 0;
		while (s[word_len] && s[word_len] != delimiter)
			++word_len;
		*words = ft_substr(s, 0, word_len);
		if (!*words)
			return (free_all(start));
		s += word_len;
		++words;
	}
	return (start);
}
