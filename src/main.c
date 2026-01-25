/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:30:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 02:30:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*b;
	t_stack	*a;

	if (ac < 2)
		return (0);
	a = parse_args_to_stack(ac, av);
	if (!a)
		return (0);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	compress_indexes(a);
	b = NULL;
	if (stack_size(a) <= 5)
		simple_sort(&a, &b);
	else
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
