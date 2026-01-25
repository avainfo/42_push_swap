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
		in_lis[arr[max_idx]] = 1;
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

static void	fill_arrays(t_stack *a, int **arr, int **dp, int **prev)
{
	t_stack	*tmp;
	int		i;
	int		size;

	size = stack_size(a);
	*arr = malloc(sizeof(int) * size);
	*dp = alloc_init_array(size, 1);
	*prev = alloc_init_array(size, -1);
	if (!*arr || !*dp || !*prev)
		exit(1);
	tmp = a;
	i = 0;
	while (tmp)
	{
		(*arr)[i++] = tmp->index;
		tmp = tmp->next;
	}
	run_lis_algo(*arr, size, *dp, *prev);
}

int	*find_lis_indices(t_stack *a, int size)
{
	int		*data[3];
	int		*in_lis;
	int		max_idx;
	int		i;

	fill_arrays(a, &data[0], &data[1], &data[2]);
	max_idx = 0;
	i = 0;
	while (i < size)
	{
		if (data[1][i] > data[1][max_idx])
			max_idx = i;
		i++;
	}
	in_lis = alloc_init_array(size, 0);
	extract_lis(in_lis, data[0], data[2], max_idx);
	free(data[0]);
	free(data[1]);
	free(data[2]);
	return (in_lis);
}
