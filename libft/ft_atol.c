/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:38:15 by ando-sou          #+#    #+#             */
/*   Updated: 2025/12/19 22:04:12 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	f;
	int		neg;

	f = 0;
	i = 0;
	neg = 1;
	while (nptr[i] && contains_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		f = f * 10 + nptr[i] - '0';
		i++;
	}
	return (f * neg);
}
