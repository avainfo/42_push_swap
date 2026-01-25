/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 03:20:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 03:45:00 by antigrav         ###   ########.fr       */
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

static void	execute_move(t_stack **a, t_stack **b, int *cnts, int method)
{
	int	tmp[2];

	tmp[0] = cnts[0];
	tmp[1] = cnts[1];
	if (method == 0)
		do_rr_rrr(a, b, tmp, 0);
	else if (method == 1)
		do_rr_rrr(a, b, tmp, 1);
	while (tmp[0] > 0)
	{
		if (method == 1 || method == 3)
			rra(a, 1);
		else
			ra(a, 1);
		tmp[0]--;
	}
	while (tmp[1] > 0)
	{
		if (method == 1 || method == 2)
			rrb(b, 1);
		else
			rb(b, 1);
		tmp[1]--;
	}
}

static int	get_node_val(t_stack *stack, int idx)
{
	int	i;

	i = 0;
	while (i < idx && stack)
	{
		stack = stack->next;
		i++;
	}
	if (stack)
		return (stack->index);
	return (0);
}

void	move_cheapest_back(t_stack **a, t_stack **b)
{
	int		method;
	int		idx_b;
	int		v[4];
	int		moves[2];

	v[1] = stack_size(*a);
	v[2] = stack_size(*b);
	idx_b = find_cheapest_b(*a, *b, &method);
	v[3] = get_node_val(*b, idx_b);
	v[0] = get_target_pos(*a, v[3]);
	moves[0] = v[0];
	moves[1] = idx_b;
	if (method == 1 || method == 3)
		if (v[0] > 0)
			moves[0] = v[1] - v[0];
	if (method == 1 || method == 2)
		if (idx_b > 0)
			moves[1] = v[2] - idx_b;
	execute_move(a, b, moves, method);
	pa(a, b, 1);
}
