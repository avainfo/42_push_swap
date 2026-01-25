/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:50:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 02:50:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

static int	find_min_pos(t_stack *a)
{
	int	min;
	int	min_pos;
	int	pos;

	min = INT_MAX;
	min_pos = 0;
	pos = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (min_pos);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		min_pos = find_min_pos(*a);
		if (min_pos <= size / 2)
			while (min_pos-- > 0)
				ra(a, 1);
		else
			while (min_pos++ < size)
				rra(a, 1);
		pb(a, b, 1);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, 1);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else
		sort_five(a, b);
}
