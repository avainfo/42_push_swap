/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 03:20:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 03:30:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_cheapest_b(t_stack *a, t_stack *b, int *method);
int	get_target_pos(t_stack *a, int val);

static void	do_rr_rrr(t_stack **a, t_stack **b, int *cnt, int reverse)
{
	while (cnt[0] > 0 && cnt[1] > 0)
	{
		if (reverse)
			rrr(a, b, 1);
		else
			rr(a, b, 1);
		cnt[0]--;
		cnt[1]--;
	}
}

static void	execute_move(t_stack **a, t_stack **b, int cost_a, int cost_b, int method)
{
	int	cnt[2];

	cnt[0] = cost_a;
	cnt[1] = cost_b;
	if (method == 0)
		do_rr_rrr(a, b, cnt, 0);
	else if (method == 1)
		do_rr_rrr(a, b, cnt, 1);
	while (cnt[0] > 0)
	{
		if (method == 1 || method == 3)
			rra(a, 1);
		else
			ra(a, 1);
		cnt[0]--;
	}
	while (cnt[1] > 0)
	{
		if (method == 1 || method == 2)
			rrb(b, 1);
		else
			rb(b, 1);
		cnt[1]--;
	}
}

/* Determine raw counts based on method and positions */
void	move_cheapest_back(t_stack **a, t_stack **b)
{
	int		method;
	int		idx_b;
	int		tgt_a;
	int		size_a;
	int		size_b;
	t_stack	*tmp;
	int		i;
	int		val;
	int		cnts[2]; /* 0: a, 1: b */

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	idx_b = find_cheapest_b(*a, *b, &method);
	tmp = *b;
	i = 0;
	while (i++ < idx_b)
		tmp = tmp->next;
	val = tmp->index;
	tgt_a = get_target_pos(*a, val);
	cnts[0] = tgt_a;
	cnts[1] = idx_b;
	if (method == 1 || method == 3)
		if (tgt_a > 0)
			cnts[0] = size_a - tgt_a;
	if (method == 1 || method == 2)
		if (idx_b > 0)
			cnts[1] = size_b - idx_b;
	execute_move(a, b, cnts[0], cnts[1], method);
	pa(a, b, 1);
}
