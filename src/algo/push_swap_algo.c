/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 03:00:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 03:00:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Correct implementation of push_non_lis */
static void	push_to_b_correct(t_stack **a, t_stack **b, int *in_lis, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (in_lis[(*a)->index])
			ra(a, 1);
		else
			pb(a, b, 1);
		i++;
	}
}

static void	rotate_to_zero(t_stack **a)
{
	int		min_pos;
	int		size;
	t_stack	*tmp;
	int		i;

	size = stack_size(*a);
	tmp = *a;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index == 0)
		{
			min_pos = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (min_pos <= size / 2)
		while ((*a)->index != 0)
			ra(a, 1);
	else
		while ((*a)->index != 0)
			rra(a, 1);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	*in_lis;
	int	n;

	n = stack_size(*a);
	in_lis = find_lis_indices(*a, n);
	push_to_b_correct(a, b, in_lis, n);
	free(in_lis);
	while (*b)
		move_cheapest_back(a, b);
	rotate_to_zero(a);
}
