/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:44:46 by nsalles           #+#    #+#             */
/*   Updated: 2023/10/17 07:02:06 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

static char	**ft_free_split(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	return (NULL);
}

static int	get_word_size(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (s[counter] != c && s[counter])
		counter++;
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wsize;
	int		i;

	if (!s)
		return (NULL);
	tab = (char **) ft_calloc(sizeof(char *), count_words(s, c) + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		wsize = get_word_size(s, c);
		if (wsize > 0)
		{
			tab[i++] = ft_substr(s, 0, wsize);
			if (!tab[i - 1])
				return (ft_free_split(tab, i - 1));
			s += wsize;
		}
	}
	tab[i] = NULL;
	return (tab);
}
