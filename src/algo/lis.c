/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:50:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 03:00:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Returns an array where arr[val] = 1 if val (index) is in LIS */
static int	*alloc_init_array(int size, int val)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
		arr[i++] = val;
	return (arr);
}

static void	extract_lis(int *in_lis, int *arr, int *prev, int max_idx)
{
	while (max_idx != -1)
	{
		in_lis[arr[max_idx]] = 1; /* Mark the value (index) as kept */
		max_idx = prev[max_idx];
	}
}

static void	run_lis_algo(int *arr, int size, int *dp, int *prev)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*find_lis_indices(t_stack *a, int size)
{
	int		*arr; /* stack values */
	int		*dp;
	int		*prev;
	int		*in_lis; /* return array */
	t_stack	*tmp;
	int		i;
	int		max_idx;

	arr = malloc(sizeof(int) * size);
	dp = alloc_init_array(size, 1);
	prev = alloc_init_array(size, -1);
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->index;
		tmp = tmp->next;
	}
	run_lis_algo(arr, size, dp, prev);
	max_idx = 0;
	i = 0;
	while (i < size)
	{
		if (dp[i] > dp[max_idx])
			max_idx = i;
		i++;
	}
	in_lis = alloc_init_array(size, 0); /* size is N, indices are 0..N-1 */
	extract_lis(in_lis, arr, prev, max_idx);
	free(arr);
	free(dp);
	free(prev);
	return (in_lis);
}
