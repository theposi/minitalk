/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:50:24 by crizapat          #+#    #+#             */
/*   Updated: 2024/03/20 00:53:34 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_counter(const char *str, char charac)
{
	size_t	i;
	size_t	words_to_save;

	i = 0;
	words_to_save = 0;
	while (str[i] != '\0')
	{
		while (str[i] == charac)
			i++;
		while (str[i] != charac && str[i] != '\0')
		{
			i++;
			if (str[i] == charac || str[i] == '\0')
				words_to_save++;
		}
	}
	return (words_to_save);
}

static char	**free_blocks(int i, char **block)
{
	while (i >= 0)
		free(block[i--]);
	free(block);
	return (NULL);
}

static char	**fill_block(const char *s, char c, char **blocks)
{
	int	i;
	int	start;
	int	position;

	i = 0;
	position = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (s[i] == c || s[i] == '\0')
			{
				blocks[position] = ft_substr(s, start, i - start);
				if (!blocks[position])
					return (free_blocks(position, blocks));
				position++;
			}
		}
	}
	return (blocks);
}

char	**ft_split(char const *str, char charac)
{
	size_t		words;
	char		**blocks;

	words = words_counter(str, charac);
	blocks = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!blocks)
		return (NULL);
	return (fill_block(str, charac, blocks));
}
