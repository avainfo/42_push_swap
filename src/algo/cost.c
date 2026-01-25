/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 03:20:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 03:55:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	update_target(t_stack *tmp, int val, int i, int *tgt_data)
{
	if (tmp->index < tgt_data[2])
	{
		tgt_data[2] = tmp->index;
		tgt_data[1] = i;
	}
	if (tmp->index > val && tmp->index < tgt_data[3])
	{
		tgt_data[3] = tmp->index;
		tgt_data[0] = i;
	}
}

int	get_target_pos(t_stack *a, int val)
{
	t_stack	*tmp;
	int		tgt_data[4];
	int		i;

	tgt_data[0] = -1;
	tgt_data[1] = -1;
	tgt_data[2] = 2147483647;
	tgt_data[3] = 2147483647;
	tmp = a;
	i = 0;
	while (tmp)
	{
		update_target(tmp, val, i, tgt_data);
		tmp = tmp->next;
		i++;
	}
	if (tgt_data[0] != -1)
		return (tgt_data[0]);
	return (tgt_data[1]);
}

static void	calc_current_costs(int *costs, int idx_a, int idx_b, int *sizes)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = idx_a;
	rb = idx_b;
	if (ra == 0)
		rra = 0;
	else
		rra = sizes[0] - ra;
	if (rb == 0)
		rrb = 0;
	else
		rrb = sizes[1] - rb;
	costs[0] = ra;
	if (rb > ra)
		costs[0] = rb;
	costs[1] = rra;
	if (rrb > rra)
		costs[1] = rrb;
	costs[2] = ra + rrb;
	costs[3] = rra + rb;
}

static void	update_best(int *best, int *costs, int *method, int idx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (costs[i] < best[0])
		{
			best[0] = costs[i];
			*method = i;
			best[1] = idx;
		}
		i++;
	}
}

int	find_cheapest_b(t_stack *a, t_stack *b, int *method)
{
	int		sizes[2];
	int		costs[4];
	int		best[2];
	int		idx;

	sizes[0] = stack_size(a);
	sizes[1] = stack_size(b);
	best[0] = 2147483647;
	idx = 0;
	while (b)
	{
		calc_current_costs(costs, get_target_pos(a, b->index), idx, sizes);
		update_best(best, costs, method, idx);
		b = b->next;
		idx++;
	}
	return (best[1]);
}
