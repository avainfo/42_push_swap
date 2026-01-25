/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:23:26 by ando-sou          #+#    #+#             */
/*   Updated: 2026/01/25 03:50:00 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_overflow(long val, int sign)
{
	if (sign == 1)
	{
		if (val > INT_MAX)
			return (-1);
	}
	if (sign == -1)
	{
		if (-val < INT_MIN)
			return (-1);
	}
	return (0);
}

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	parse_one_int(const char *s, int *i, int *out)
{
	int		sign;
	long	val;

	while (s[*i] && is_space(s[*i]))
		(*i)++;
	if (!s[*i])
		return (0);
	sign = 1;
	if (is_sign(s[*i]))
	{
		if (s[(*i)++] == '-')
			sign = -1;
	}
	if (s[*i] < '0' || s[*i] > '9')
		return (-1);
	val = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		val = val * 10 + (s[*i] - '0');
		if (check_overflow(val, sign) == -1)
			return (-1);
		(*i)++;
	}
	*out = (int)(val * sign);
	return (1);
}
