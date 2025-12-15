/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:38:08 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/23 23:13:55 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*si;
	unsigned char		*di;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	di = (unsigned char *) dest;
	si = (const unsigned char *) src;
	if (di < si)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n--)
			di[n] = si[n];
	}
	return (dest);
}
