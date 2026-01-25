/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:40:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 14:40:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_all_and_exit(t_stack **a, t_stack **b, char *line)
{
	if (line)
		free(line);
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_strcmp_chk(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	exec_instruction(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == '\0') 
		free_all_and_exit(a, b, line);
	if (!ft_strcmp_chk(line, "sa"))
		sa(a, 0);
	else if (!ft_strcmp_chk(line, "sb"))
		sb(b, 0);
	else if (!ft_strcmp_chk(line, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp_chk(line, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp_chk(line, "pb"))
		pb(a, b, 0);
	else if (!ft_strcmp_chk(line, "ra"))
		ra(a, 0);
	else if (!ft_strcmp_chk(line, "rb"))
		rb(b, 0);
	else if (!ft_strcmp_chk(line, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp_chk(line, "rra"))
		rra(a, 0);
	else if (!ft_strcmp_chk(line, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp_chk(line, "rrr"))
		rrr(a, b, 0);
	else
		free_all_and_exit(a, b, line);
}

void	parse_and_run(t_stack **a, t_stack **b)
{
	char	*line;
	int		len;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		exec_instruction(a, b, line);
		free(line);
	}
}
