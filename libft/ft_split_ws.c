/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:01:01 by ando-sou          #+#    #+#             */
/*   Updated: 2026/01/25 01:14:22 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s)
{
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
		{
			n++;
			while (s[i] && !ft_isspace(s[i]))
				i++;
		}
	}
	return (n);
}

static char	*ft_worddup(char const *s)
{
	size_t	len;
	size_t	i;
	char	*w;

	len = 0;
	while (s[len] && !ft_isspace(s[len]))
		len++;
	w = (char *)malloc(len + 1);
	if (!w)
		return (NULL);
	i = 0;
	while (i < len)
	{
		w[i] = s[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

static void	*ft_free_tab(char **tab, size_t used)
{
	size_t	i;

	i = 0;
	while (i < used)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**alloc_tab(char const *s)
{
	char	**tab;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count_words(s);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (tab)
		tab[count] = NULL;
	return (tab);
}

char	**ft_split_whitespace(char const *s)
{
	char	**tab;
	size_t	i;

	tab = alloc_tab(s);
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s)
		{
			tab[i] = ft_worddup(s);
			if (!tab[i])
				return (ft_free_tab(tab, i));
			i++;
			while (*s && !ft_isspace(*s))
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
