/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:07:53 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/23 23:09:05 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*si;
	unsigned char		*di;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	i = 0;
	di = (unsigned char *) dest;
	si = (const unsigned char *) src;
	while (i < n)
	{
		di[i] = si[i];
		i++;
	}
	return (dest);
}
