/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:24:07 by ando-sou          #+#    #+#             */
/*   Updated: 2026/01/25 02:28:20 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*parse_args_to_stack(int ac, char **av) {
	t_stack	*a;
	int		i;
	int		j;
	int		x;
	int		parsed;
	int		r;

	a = NULL;
	i = 1;
	while (i < ac) {
		j = 0;
		parsed = 0;
		while (1) {
			r = parse_one_int(av[i], &j, &x);
			if (r == 1) {
				stack_add_back(&a, stack_new(x));
				parsed = 1;
				continue ;
			}
			if (r == 0)
				break ;
			error_exit(&a);
		}
		if (!parsed)
			error_exit(&a);
		i++;
	}
	if (has_duplicates_stack(a))
		error_exit(&a);
	return (a);
}
