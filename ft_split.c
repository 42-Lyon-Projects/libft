/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:30:20 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/27 23:30:20 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_delimiter(const char *string, char delimiter)
{
	int	index;
	int	delimiters;

	index = 0;
	delimiters = 0;
	while (string[index])
	{
		while (string[index] == delimiter)
			index++;
		if (string[index])
		{
			while (string[index] && string[index] != delimiter)
				index++;
			delimiters++;
		}
	}
	return (delimiters);
}

void	ft_free_split(char **words_list)
{
	int	index;

	index = 0;
	while (words_list[index])
		free(words_list[index++]);
	free(words_list);
}

static char	**fill_array(const char *s, char c, char **words_list)
{
	int	i;
	int	delimiters;
	int	word_s;

	i = 0;
	delimiters = 0;
	while (s[i])
	{
		word_s = 0;
		if (s[i] != c && i + word_s < (int) ft_strlen(s))
		{
			while (s[i + word_s] != c && i + word_s < (int) ft_strlen(s))
				word_s++;
			words_list[delimiters] = ft_substr(s, ((unsigned int) i), word_s);
			if (!words_list[delimiters])
			{
				ft_free_split(words_list);
				return (NULL);
			}
			i = i + word_s -1;
			delimiters++;
		}
		i++;
	}
	return (words_list);
}

char	**ft_split(char const *s, char c)
{
	char	**words_list;
	int		count_delimiters;

	if (!s)
		return (NULL);
	count_delimiters = count_delimiter(s, c);
	words_list = ft_calloc(count_delimiters + 1, sizeof(char *));
	if (!words_list)
		return (NULL);
	return (fill_array(s, c, words_list));
}
