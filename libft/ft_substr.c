/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:21:10 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/20 16:54:39 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	maxlen;
	char	*sub_s;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		sub_s = (char *) malloc(1);
		if (!sub_s)
			return (NULL);
		sub_s[0] = 0;
		return (sub_s);
	}
	maxlen = slen - (size_t) start;
	if (len < maxlen)
		maxlen = len;
	sub_s = malloc(sizeof(char) * (maxlen + 1));
	if (!sub_s)
		return (NULL);
	ft_memcpy(sub_s, s + start, maxlen);
	sub_s[maxlen] = 0;
	return (sub_s);
}
