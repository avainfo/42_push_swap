/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:23:26 by ando-sou          #+#    #+#             */
/*   Updated: 2025/12/19 22:30:02 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parse_one_int(const char *s, int *i, int *out)
{
	int		sign;
	long	val;

	while (s[*i] && is_space(s[*i]))
		(*i)++;
	if (!s[*i])
		return (0);
	sign = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (s[*i] < '0' || s[*i] > '9')
		return (-1);
	val = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		val = val * 10 + (s[*i] - '0');
		if (sign == 1 && val > (long)INT_MAX)
			return (-1);
		if (sign == -1 && -val < (long)INT_MIN)
			return (-1);
		(*i)++;
	}
	*out = (int)(val * sign);
	return (1);
}