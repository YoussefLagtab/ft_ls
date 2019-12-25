/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:56:23 by mel-idri          #+#    #+#             */
/*   Updated: 2019/10/07 14:05:39 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *s, char c)
{
	int		words;
	size_t	i;
	int		is_in_word;

	i = 0;
	words = 0;
	is_in_word = 0;
	while (s[i])
	{
		if (!is_in_word && s[i] != c)
		{
			is_in_word = 1;
			words++;
		}
		else if (is_in_word && s[i] == c)
			is_in_word = 0;
		i++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	end;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if ((words = (char **)ft_memalloc((count_words(s, c) + 1) * sizeof(char *)))
			== NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		words[j++] = end - start > 0 ? ft_strsub(s, start, end - start) : NULL;
	}
	return (words);
}
