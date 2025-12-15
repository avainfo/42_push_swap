/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:21:22 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/23 23:26:08 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static char	*ft_worddup(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*w;

	len = 0;
	while (s[len] && s[len] != c)
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

static char	**alloc_tab(char const *s, char c)
{
	char	**tab;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (tab)
		tab[count] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;

	tab = alloc_tab(s, c);
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			tab[i] = ft_worddup(s, c);
			if (!tab[i])
				return (ft_free_tab(tab, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
