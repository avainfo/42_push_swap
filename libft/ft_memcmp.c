/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:02 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/20 12:20:22 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*st1;
	const unsigned char	*st2;

	st1 = (const unsigned char *) s1;
	st2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i + 1 < n && st1[i] == st2[i])
		i++;
	return (st1[i] - st2[i]);
}
