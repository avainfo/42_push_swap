/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:40:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 02:40:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (!stack || !stack->next)
		return ;
	tmp_val = stack->value;
	tmp_idx = stack->index;
	stack->value = stack->next->value;
	stack->index = stack->next->index;
	stack->next->value = tmp_val;
	stack->next->index = tmp_idx;
}

void	sa(t_stack **a, int print)
{
	swap(*a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	swap(*b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(*a);
	swap(*b);
	if (print)
		write(1, "ss\n", 3);
}
