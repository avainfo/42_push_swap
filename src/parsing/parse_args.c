/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:24:07 by ando-sou          #+#    #+#             */
/*   Updated: 2026/04/19 15:25:03 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	process_arg_string(char *s, t_stack **a)
{
	int		j;
	int		val;
	int		ret;
	int		cnt;

	j = 0;
	cnt = 0;
	while (1)
	{
		ret = parse_one_int(s, &j, &val);
		if (ret == 1)
		{
			stack_add_back(a, stack_new(val));
			cnt++;
		}
		else if (ret == 0)
			break ;
		else
			error_exit(a);
	}
	if (cnt == 0)
		error_exit(a);
}

t_stack	*parse_args_to_stack(int ac, char **av)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		process_arg_string(av[i], &a);
		i++;
	}
	if (has_duplicates_stack(a))
		error_exit(&a);
	return (a);
}
