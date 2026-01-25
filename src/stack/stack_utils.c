/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:30:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 02:30:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	has_duplicates_stack(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*runner;

	tmp = a;
	while (tmp)
	{
		runner = tmp->next;
		while (runner)
		{
			if (tmp->value == runner->value)
				return (1);
			runner = runner->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}
