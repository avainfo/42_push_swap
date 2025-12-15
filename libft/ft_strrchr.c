/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:41:41 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/23 23:42:56 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			last = ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) c == 0)
		return ((char *) &s[i]);
	return (last);
}
