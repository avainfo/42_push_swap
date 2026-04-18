/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:49:33 by ando-sou          #+#    #+#             */
/*   Updated: 2026/04/18 17:08:29 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

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

void	error_exit(t_stack **s);
int		has_duplicates_stack(t_stack *a);
int		is_sorted(t_stack *a);
void	compress_indexes(t_stack *a);

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* Algo */
void	simple_sort(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
int		*find_lis_indices(t_stack *a, int size);
void	move_cheapest_back(t_stack **a, t_stack **b);
int		find_cheapest_b(t_stack *a, t_stack *b, int *method);
int		get_target_pos(t_stack *a, int val);

#endif
