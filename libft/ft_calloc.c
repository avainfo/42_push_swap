/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:53:36 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/25 18:04:15 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*x;

	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	i = size * nmemb;
	x = malloc(i);
	if (!x)
		return (NULL);
	ft_bzero(x, i);
	return (x);
}
