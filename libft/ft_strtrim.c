/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:05 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/23 23:41:37 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	get_se(size_t *st, size_t *en, char const *s1, char const *set)
{
	size_t	s;
	size_t	e;

	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_contains(s1[s], set))
		s++;
	while (e > s && ft_contains(s1[e - 1], set))
		e--;
	*st = s;
	*en = e;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	get_se(&start, &end, s1, set);
	len = end - start;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1 + start, len);
	s[len] = 0;
	return (s);
}
