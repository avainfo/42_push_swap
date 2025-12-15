/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:56:18 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/23 23:03:13 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long temp_n)
{
	int	len_n;

	len_n = 0;
	while (temp_n > 0)
	{
		len_n++;
		temp_n /= 10;
	}
	return (len_n);
}

static char	*checks(int n, int *neg, long *ln, int *len_n)
{
	char	*first;
	int		size;

	if (n < 0)
		*neg = 1;
	if (*neg)
		*ln *= -1;
	*len_n = count_digits(*ln);
	size = *len_n + *neg + 1 + (n == 0);
	first = malloc(size);
	if (!first)
		return (NULL);
	if (*ln == 0)
		first[0] = '0';
	return (first);
}

char	*ft_itoa(int n)
{
	char	*first;
	int		len_n;
	int		neg;
	long	ln;

	neg = 0;
	ln = n;
	first = checks(n, &neg, &ln, &len_n);
	if (!first)
		return (NULL);
	first[len_n + neg + (ln == 0)] = 0;
	while (ln > 0)
	{
		first[len_n + neg - 1] = ln % 10 + '0';
		ln /= 10;
		len_n--;
	}
	if (neg)
		first[0] = '-';
	return (first);
}
