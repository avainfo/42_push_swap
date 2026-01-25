/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigrav <antigrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:30:00 by antigrav          #+#    #+#             */
/*   Updated: 2026/01/25 02:30:00 by antigrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Simple bubble sort for the array, adequate for N=500 */
static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_indexes(t_stack *stack, int *arr, int size)
{
	t_stack	*ptr;
	int		i;

	ptr = stack;
	while (ptr)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == ptr->value)
			{
				ptr->index = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
}

void	compress_indexes(t_stack *stack)
{
	int		size;
	int		*arr;
	t_stack	*ptr;
	int		i;

	size = stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit(&stack);
	ptr = stack;
	i = 0;
	while (ptr)
	{
		arr[i++] = ptr->value;
		ptr = ptr->next;
	}
	sort_int_array(arr, size);
	assign_indexes(stack, arr, size);
	free(arr);
}
