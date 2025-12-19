/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:49:33 by ando-sou          #+#    #+#             */
/*   Updated: 2025/12/19 22:27:39 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		is_space(char c);
int		parse_one_int(const char *s, int *i, int *out);
t_stack	*parse_args_to_stack(int ac, char **av);

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **s, t_stack *n);
void	free_stack(t_stack **s);
int		stack_size(t_stack *a);
void	fill_array_from_stack(t_stack *a, int *arr);

void	error_exit(t_stack **s);
void	quicksort_int(int *arr, int l, int r);
int		has_duplicates_stack(t_stack *a);

#endif
