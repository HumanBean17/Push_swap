/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:07:57 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/14 16:47:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(const char *str, char c)
{
	int	words;
	int	i;
	int	j;

	i = 0;
	j = 0;
	words = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[j] == c)
			j++;
		i = j;
		while (str[i] != c && str[i] != '\0')
			i++;
		i--;
		if (str[i] != c && str[i] != '\0')
			words++;
		i++;
	}
	return (words);
}

static int		skip_tabs(const char *str, int i, char c)
{
	while (str[i] == c)
		i++;
	return (i);
}

static int		skip_letter(const char *str, int i, char c)
{
	int k;

	k = 0;
	while (str[i] != c && str[i] != '\0')
	{
		k++;
		i++;
	}
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**k;
	int		i;
	int		j;
	int		l;

	if (!s)
		return (NULL);
	i = 0;
	l = 0;
	k = (char **)ft_memalloc(sizeof(char *) * (1 + word_count(s, c)));
	while (s[i] != '\0')
	{
		i = skip_tabs(s, i, c);
		j = skip_letter(s, i, c);
		if (j == 0)
			break ;
		if (!(k[l++] = ft_strsub(s, i, j)))
			return (NULL);
		i += j;
	}
	if (word_count(s, c) == 0)
		ft_strdel(&k[0]);
	k[word_count(s, c)] = NULL;
	return (k);
}
