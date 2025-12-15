/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:19:37 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/20 16:28:31 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*r;

	len = ft_strlen(s);
	r = malloc(sizeof(char) * (len + 1));
	if (r == NULL)
		return (NULL);
	ft_memcpy(r, s, len);
	r[len] = 0;
	return (r);
}
