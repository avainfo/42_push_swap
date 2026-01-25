/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 03:20:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 03:20:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_target_pos(t_stack *a, int val)
{
	t_stack	*tmp;
	int		tgt;
	int		min;
	int		i;
	int		min_val;
	int		tgt_val;

	tgt = -1;
	min = -1;
	min_val = INT_MAX;
	tgt_val = INT_MAX;
	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->index < min_val)
		{
			min_val = tmp->index;
			min = i;
		}
		if (tmp->index > val && tmp->index < tgt_val)
		{
			tgt_val = tmp->index;
			tgt = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (tgt != -1)
		return (tgt);
	return (min);
}

static int	max_val(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	get_costs(int ra, int rb, int sa, int sb, int *cost)
{
	int	rra;
	int	rrb;

	if (ra == 0)
		rra = 0;
	else
		rra = sa - ra;
	if (rb == 0)
		rrb = 0;
	else
		rrb = sb - rb;
	cost[0] = max_val(ra, rb);
	cost[1] = max_val(rra, rrb);
	cost[2] = ra + rrb;
	cost[3] = rra + rb;
}

static void	update_best(int *current, int *best, int *best_m, int idx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (current[i] < *best)
		{
			*best = current[i];
			*best_m = i;
			best_m[1] = idx; /* store index of B */
		}
		i++;
	}
}

/* Returns index in B that is cheapest, sets method in `method` */
/* method: 0=rr, 1=rrr, 2=ra+rrb, 3=rra+rb */
/* We iterate B. For each node, get target pos in A (and thus costs) */
int	find_cheapest_b(t_stack *a, t_stack *b, int *method)
{
	int		idx;
	int		costs[4];
	int		best_cost;
	int		best_data[2]; /* [method, index_in_b] */
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	best_cost = INT_MAX;
	idx = 0;
	while (b)
	{
		get_costs(get_target_pos(a, b->index), idx, size_a, size_b, costs);
		update_best(costs, &best_cost, &best_data[0], idx);
		b = b->next;
		idx++;
	}
	*method = best_data[0];
	return (best_data[1]);
}
