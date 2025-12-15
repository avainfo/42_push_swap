/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:13:45 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/24 18:22:43 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nn;

	nn = malloc(sizeof(t_list));
	if (!nn)
		return (NULL);
	nn->content = content;
	nn->next = NULL;
	return (nn);
}
