/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:30:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 14:30:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../includes/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* checker_read_bonus.c */
char	*get_next_line(int fd);

/* checker_exec_bonus.c */
void	exec_instruction(t_stack **a, t_stack **b, char *line);
void	parse_and_run(t_stack **a, t_stack **b);

#endif
